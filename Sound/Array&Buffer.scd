s.boot

s.plotTree;

b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav");

b.numFrames
d = 200;
n = b.numFrames/d;

////////////////////////// OSC_COM//////////////////////////////////////
//Receiving data
m = NetAddr.new("127.0.0.1",12000); //listening to processing port 12000
m.sendMsg("/rows:",d); //how to send a variable ?

//Sending data
NetAddr.localAddr // asking supercollider for listening port for OSC communication
(
OSCdef('listener',{
	Synth(\Sample_size, [\bufnum, b.bufnum]);
}, "/rows"); //segment of the cloud played
)

n.postln; //command for console printing
////////////////////////////////////////////////////////////////////////


///access to predetermined frame in sample
(
x= {
	var sig;
	sig = PlayBuf.ar(
		1,
		b,
		1,
		1,
		n,
		doneAction:2
	);
}.play;
)

//access to start and end of frame in sample
// 0 to numFrames for whole sample
{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), 0, n),0) }.play;  //<-- get into synthDef?

(
SynthDef(\Sample_size, { |out = 0, bufnum = 0, amp = 0.4, dur = 0.5|
    var phasor, sound, env;
	env = EnvGen.kr(Env.sine(dur , amp), doneAction:2); //doneAction:2
	phasor = Phasor.ar(0, BufRateScale.kr(bufnum), 0, n);
    sound = BufRd.ar(1, bufnum, phasor, 0);
    Out.ar(out, sound);
}).add;
)

x = Synth(\Sample_size, [\bufnum, b.bufnum]);



{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), n, n*2),0) }.play;

///test
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
