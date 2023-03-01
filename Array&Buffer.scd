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
{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), 0, n),0) }.play;

{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), n, n*2),0) }.play;
