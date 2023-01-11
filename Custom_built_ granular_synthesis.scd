s.boot;
(
SynthDef.new(\sineGrain, {
	arg freq=800,
	amp=0.4,
	dur=0.1,
	pan=0;
	var signal, env;
	// A Gaussian curve envelope that's released from the server after playback
	env = EnvGen.kr(Env.sine(dur, amp), doneAction: 2);
	signal = FSinOsc.ar(freq, 0, env);
	OffsetOut.ar(0, Pan2.ar(signal, pan));
}).add;
)
Synth(\sineGrain, [\freq, 500, \dur, 0.05]) // 50 ms grain duration

// we can then trigger 1000 grains, one every 10 ms
(
Task({
   1000.do({
   		Synth(\sineGrain,
			[\freq, rrand(50, 1600), //
			\amp, rrand(0.1,0.3),
			\dur, rrand(0.02, 0.1)
			]);
		0.01.wait;
	});
}).start;
)




/////////////////////AWSOME DRONE/////////////////////////
(
SynthDef.new(\saw, {
	arg cutoff=1000;
	var sig;
	sig = Saw.ar([50,51]);
	sig = RLPF.ar(sig, cutoff.lag(0.02), 0.25, 0.2);
	Out.ar(0, sig);
}).add;
)

Synth(\saw, [\freq, 500, \dur, 0.05])

~synth = Synth(\saw, [\cutoff, 200]);
~synth.set(\cutoff, 10000);
~synth.free;

(
Task({
   1000.do({
   		Synth(\saw,
			[\freq, rrand(50, 1600), //
			\amp, rrand(0.1,0.3),
			\dur, rrand(0.02, 0.1)
			]);
		0.01.wait;
	});
}).start;
)