s.boot

b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav");

b.numFrames
t = b.numFrames * 0.50; ///start frame in sample
e = b.numFrames *0.505;
///difference between t and e size of  cloud

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


{ BufRd.ar(1, b.bufnum, Phasor.ar(0, BufRateScale.kr(b.bufnum), t, e )) }.play;