//////////////////////////////////////////////////
//Percussion envelope, rapid attack, controlled decay
//////////////////////////////////////////////////
(
SynthDef(\sineGrainWPercEnv, { arg freq = 800, amp = 0.1, envdur = 0.1, pan=0;
	var signal;
	signal = FSinOsc.ar(freq, 0, EnvGen.kr(Env.perc(0.001, envdur), doneAction: 2)*amp);
	OffsetOut.ar(0, Pan2.ar(signal, pan));
}).add;
)

(
Task({
   1000.do({
		s.bind{
			Synth(\sineGrainWPercEnv,
				[\freq, rrand(1300, 4000),
				\amp, rrand(0.1, 0.2),
				\envdur, rrand(0.1, 0.2),
				\pan, 1.0.rand2
			]);
		};
		0.01.wait; // density
	});
}).start;
)

//////////////////////////////////////////////////
//Expodec. envelope
//////////////////////////////////////////////////

(
SynthDef(\expodecGrain, { arg freq=800, amp=0.4, dur=0.1, pan=0;
	var signal, env;
	//Exponential Decay Envelope (Expodec.)
	env=EnvGen.kr(Env.new([0,1,0],[0,dur],'exp'), doneAction: 2) *amp;
	signal = FSinOsc.ar(freq, 0, env);
	OffsetOut.ar(0, Pan2.ar(signal, pan));
}).add;
)

(
Task({
   1000.do({
		s.bind{
			Synth(\expodecGrain,
				[\freq, rrand(1300, 4000),
				\amp, rrand(0.1, 0.2),
				\envdur, rrand(0.1, 0.2),
				\pan, 1.0.rand2
			]);
		};
		0.01.wait; // density
	});
}).start;
)

////////////////////////////////////////////////////
// Gaussian Envelope
///////////////////////////////////////////////
(
SynthDef(\gaussianGrain, { arg freq = 440, amp = 0.5, dur = 0.1, pan = 0;
    var signal, env;

    // Approximating a Gaussian envelope
    env = EnvGen.kr(
        Env.pairs(
            [[0, 0], [dur * 0.5, amp], [dur, 0]],
            curve: [-4, 4] // Use curves to simulate the Gaussian shape
        ),
        doneAction: 2
    );

    signal = SinOsc.ar(freq, 0, env);
    OffsetOut.ar(0, Pan2.ar(signal, pan));
}).add;
)

(
Task({
    1000.do({
        Synth(\gaussianGrain,
            [\freq, rrand(440, 1600),
             \amp, rrand(0.1, 0.3),
             \dur, rrand(0.05, 0.2), // Varying duration
             \pan, rrand(-1, 1)     // Random stereo panning
        ]);
        0.05.wait; // Adjust this for grain density
    });
}).play;
)


