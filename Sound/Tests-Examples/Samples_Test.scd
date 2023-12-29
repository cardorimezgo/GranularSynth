Server.killAll;
s.boot;

b= Buffer.read(s,"C:/Users/cardo/Documents/openFrameworks/apps/myApps/GranularSynth/Audio_Samples/Sound_Samples_668451__strangehorizon__zephy-people-act.wav");

b.play;


(
SynthDef(\sineGrain, {arg freq=800, amp=0.4,dur=0.1, pan=0;
	var signal, env;
	env = EnvGen.kr(Env.sine(dur,amp), doneAction: 2);
	signal = FSinOsc.ar(freq,0,env);
	OffsetOut.ar(0, Pan2.ar(signal, pan));
}).add;
)
////////
Synth(\sineGrain, [\freq, 500, \dur, 0.05]) //50ms grain duration
////////
(
Task({
	1000.do({
		Synth(\sineGrain,
			[\freq, rrand(440,1600),
				\amp, rrand(0.1,0.3),
				\dur, rrand(0.02, 0.1)
		]);
		0.01.wait;
	});
}).start
)
/////////////////////////////////////////////////////////////////////

(
SynthDef(\sineGrain, {arg freq=800, amp=0.4, dur=0.1, pan=0, durVariation=0;
	var signal, env, actualDur;
	actualDur = dur * (1+ LFNoise1.kr(1)* durVariation);
	env=EnvGen.kr(Env.sine(actualDur, amp), doneAction:2);
	signal = FSinOsc.ar(freq,0,env);
	OffsetOut.ar(0, Pan2.ar(signal,pan));
}).add
)

Synth(\sineGrain, [\freq, 500, \dur, 0.05, \durVariation, 0.5])

(
Task({
	1000.do({
		Synth(\sineGrain,
			[\freq, rrand(440,1600),
				\amp, rrand(0.1,0.3),
				\dur, rrand(0.02, 0.1)
		]);
		0.01.wait;
	});
}).start
)

///////////////////////////////////////////////////////////////////////////
(
SynthDef(\sineGrainConstantDur, { arg freq=800, amp=0.4, dur=0.1, pan=0;
    var signal, env;
    // Constant duration for each grain
    env = EnvGen.kr(Env.sine(dur, amp), doneAction: 2);
    signal = FSinOsc.ar(freq, 0, env);
    OffsetOut.ar(0, Pan2.ar(signal, pan));
}).add;
)

// Testing the constant duration
Synth(\sineGrainConstantDur, [\freq, 500, \dur, 0.05]) // 50ms constant grain duration

(
Task({
    1000.do({
        Synth(\sineGrainConstantDur,
            [\freq, 440,
             \amp, 0.1,
             \dur, 0.05 // Constant duration for all grains
        ]);
        0.01.wait;
    });
}).start;
)
