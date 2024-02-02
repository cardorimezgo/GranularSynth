s.boot;


b = Buffer.read(s , "C:/Users/cardo/Documents/openFrameworks/apps/myApps/GranularSynth/Audio_Samples/Sound_Samples_668451__strangehorizon__zephy-people-act.wav");

(
SynthDef(\sampleAmpAnalysis, { |bufnum|
	var signal, fft, ifft, chain;

	//Play the buffer and loop it
	signal = PlayBuf.ar(1,bufnum,loop:1);

	//Perform FFT
	fft = FFT(LocalBuf(2048),signal);

	//Example processing (not altering the sound in this case) this is where we could manipulate or analyze the FFT
	chain = PV_BinScramble(fft, wipe:0);

	//Convert FFT back to audio signal
	ifft = IFFT(chain);

	//Output audio(for monitoring purposes)
	Out.ar(0 , ifft);

	//Monitor the overall level of the FFT(amplitude in a crude sense)
	Poll.ar(Impulse.ar(2), Amplitude.ar(ifft), label: "Amplitude");
}).add;
)

x= Synth(\sampleAmpAnalysis, [\bufnum, b.bufnum]);

x.free;
b.free;