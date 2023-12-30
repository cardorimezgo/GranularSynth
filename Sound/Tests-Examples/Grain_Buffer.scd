b = Buffer.read(s, "C:/Users/cardo/Documents/openFrameworks/apps/myApps/GranularSynth/Audio_Samples/Sound_Samples_668451__strangehorizon__zephy-people-act.wav");

(
SynthDef(\bufGrain, {arg out=0, buffer, rate=1.0, amp=0.1, dur=0.1, startPos=0;
	var signal;
	signal= PlayBuf.ar(1, buffer, rate, 1, startPos)*EnvGen.kr(Env.sine(dur,amp),doneAction:2);
	OffsetOut.ar(out,signal !2)
}).add;
)

Synth(\bufGrain, [\buffer,b]);

(
Task({
	1000.do({arg i;
		Synth(\bufGrain,
			[\buffer, b,
				\rate, rrand(0.8, 1.2),
				\amp, rrand(0.05, 0.2),
				\dur, rrand(0.06, 0.1),
				\startPos, i*100//jumping 100 samples per grain
		]);
		0.001.wait;
	});
}).start;
)

///////////////////////////////////////////////////////////////
//Using a Percussion Envelope for each grain of the audio sample
///////////////////////////////////////////////////////////

(
SynthDef(\bufEnvGrainPerc, { arg out=0, buffer, rate=1.0, amp=0.1, dur=0.1, startPos=0;
    var signal, env;

    // Percussive envelope
    env = EnvGen.kr(Env.perc(0.001, dur, amp, -4), doneAction: 2);

    signal = PlayBuf.ar(1, buffer, rate, 1, startPos, loop: 0) * env;
    OffsetOut.ar(out, signal ! 2); // Stereo output
}).add;
)


(
Task({
    1000.do({ arg i;
        Synth(\bufEnvGrainPerc,
            [\buffer, b,
             \rate, rrand(0.8, 1.2),
             \amp, rrand(0.05, 0.2),
             \dur, rrand(0.06, 0.1),
             \startPos, i * 100  // jumping 100 samples per grain
            ]);
        0.09.wait;
    });
}).start;
)

///////////////////////////////////////////////////////////////
//Using Gaussian Envelope for each grain of the audio sample
///////////////////////////////////////////////////////////

(
SynthDef(\bufEnvGrainGauss, { arg out=0, buffer, rate=1.0, amp=0.1, dur=0.1, startPos=0;
    var signal, env;

	 env = EnvGen.kr(
        Env.pairs(
            [[0, 0], [dur * 0.5, amp], [dur, 0]],
            curve: [-4, 4] // Use curves to simulate the Gaussian shape
        ),
        doneAction: 2
    );
    signal = PlayBuf.ar(1, buffer, rate, 1, startPos, loop: 0) * env;
    OffsetOut.ar(out, signal ! 2); // Stereo output
}).add;
)


(
Task({
    1000.do({ arg i;
        Synth(\bufEnvGrainGauss,
            [\buffer, b,
             \rate, rrand(0.8, 1.2),
             \amp, rrand(0.05, 0.2),
             \dur, rrand(0.06, 0.1),
             \startPos, i * 100  // jumping 100 samples per grain
            ]);
        0.09.wait;
    });
}).start;
)
