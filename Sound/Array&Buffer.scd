s.boot
s.plotTree;
b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav");

c = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/japanese-yes.wav");

c.numFrames
b.numFrames
d=50;
n = b.numFrames/d;

///access to predetermined frame in sample
(
x= {
	var sig;
	sig = PlayBuf.ar(
		1,
		b,
		1,
		1,
		n, ////
		doneAction:2
	);
}.play;
)

//access to start and end of frame in sample
// 0 to numFrames for whole sample
{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), 0, n),0) }.play;  //<-- get into synthDef?

{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), n, n*2),0) }.play;

{TGrains.ar(2, Impulse.ar(MouseY.kr(1, 30)), b, 1, MouseX.kr(0,BufDur.kr(b)), 2/MouseY.kr(1, 10), 0, 0.8, 2)}.play

(
SynthDef(\testa,{arg  freq = 800, amp = 0.4, dur = 0.1, pan = 0; //out = 0
	var signal, env;
	env = EnvGen.kr(Env.sine(dur,amp),doneAction:2); //doneAction:2
	signal =  BufRd.ar(1, b.bufnum, Phasor.ar(0,        BufRateScale.kr(b.bufnum), n,n*2),0);
	//Out.ar(out, signal)
	OffsetOut.ar(0,Pan2.ar(signal,pan));
}).add
)

x = Synth(\testa, [\freq, 100, \dur, 0.50])

(
Task({
	1000.do({
		s.bind{
		Synth(\testa,
			[\freq,440,
				\amp,0.4,
				\dur,0.5
		]);
		};
		0.08.wait; //grain density?
	});
}).start;
)