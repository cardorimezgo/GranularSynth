s.boot

b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav");

c = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/japanese-yes.wav");

c.numFrames
b.numFrames

h = b.numFrames - 409900;
i =  b.numFrames - 100000;
t = b.numFrames * 0.001; ///start frame in sample
e = b.numFrames *0.999; ///end frmae in sample

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
{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), 0, 300)) }.play;

{ BufRd.ar(1, c.bufnum, Phasor.ar(0, BufRateScale.kr(c.bufnum), 0, 1000)) }.play;
