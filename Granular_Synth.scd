s.boot;
//o = Server.default.options;
//o.outDevice_("Windows WASAPI : Speakers");
//Server.default.reboot;
//{SinOsc.ar}.play;

(
s.meter;
s.plotTree;
s.scope;
)


b = Buffer.readChannel(s,"E:/Interface/Audio/PD_patches/piano_twoMin_mono_44100.wav",channels:[0]); /// audio must be mono
b.play;
b.duration/5;
b.numChannels;
b.free;

//// HOW IS THE SAMPLE ORDERED, FEEDED INTO THE ALGORITHM??? From Andy Farnell's "designing sounds" p.308 Asynchonous granular synthesis: Often the location in the source file is chosen from a Gaussian distribution, or maybe completly at random. Another technique is to use random walks around some point in the file or the zigzag method where the time direction reverses ocassionanlly.

(
{
	var sig;
	sig = GrainBuf.ar(
		2, // number of channels
		Impulse.ar(100), //grains per second  Dust= asynchronous granulation
		1/20, //Duration of individual grains per sec
		b, //buffer
		1.5,//ratio play back seed
		(
			LFSaw.ar(2/BufDur.ir(b)).range(0, BufSamples.ir(b)-1)
		+ LFNoise1.ar(100).bipolar(0.01 * SampleRate.ir)
		) / BufSamples.ir(b),//location in buffer where we start
		2,//
		0,
		-1, //grain envelope
		512
	);
	sig = sig * 0.5;
}.play
)
