////////////////////////////////////////////////////////////////////
//reverb effect with FreeVerb
////////////////////////////////////////////////////////////////

(
SynthDef(\granularReverb, { arg out=0, buffer, rate=1, grainDur=0.1, density=20, roomSize=0.9, mix=0.5;
    var source, grains, reverb;

    // Granular Synthesis
    grains = TGrains.ar(2, Impulse.ar(density), buffer, rate, LFNoise1.kr(0.1).range(0, BufDur.kr(buffer)), grainDur);

    // Reverb Effect
    reverb = FreeVerb.ar(grains, roomSize, mix, 0.5);

    // Output
    Out.ar(out, reverb);
}).add;
)

(
Task({
    Synth(\granularReverb, [\buffer, b, \rate, 1, \grainDur, 0.1, \density, 25, \roomSize, 0.7, \mix, 0.5]);
    2.wait; // Duration for which the reverb effect will play
}).play;
)

//////////////////////////////////////////////////////////////////////////////
//reverb integration with Granular Synthesis
//////////////////////////////////////////////////////////////////////////////

(
SynthDef(\bufEnvGrainPerc, { arg out=0, buffer, rate=1.0, amp=0.1, dur=0.1, startPos=0, roomSize=0.5, mix=0.5;
    var signal, env, reverb;

    // Percussive envelope
    env = EnvGen.kr(Env.perc(0.001, dur, amp, -4), doneAction: 2);

    // Signal with PlayBuf and envelope
    signal = PlayBuf.ar(1, buffer, rate, 1, startPos, loop: 0) * env;

    // Reverb Effect
    reverb = FreeVerb.ar(signal, roomSize, mix, 0.5);

    // Output the reverberated signal
    OffsetOut.ar(out, reverb ! 2); // Stereo output
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
        0.1.wait;
    });
}).start;
)