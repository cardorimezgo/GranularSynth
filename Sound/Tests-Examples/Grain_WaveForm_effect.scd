
/////////////
// Generation of grains where each grain is assigned a different waveform
// changing the envelope of each grain according to the random function
//////////////

(
SynthDef(\multiWaveGrain, { arg freq=800, amp=0.4, dur=0.1, pan=0, waveform=0;
    var signal, env, wave;
    env = EnvGen.kr(Env.perc(0.01, dur, amp, -4), doneAction: 2);

    // Select waveform based on 'waveform' argument
    wave = Select.ar(waveform, [
        SinOsc.ar(freq, 0, env), // Sine wave
        Saw.ar(freq, env),       // Sawtooth wave
        Pulse.ar(freq, 0.5, env),// Square wave
        LFTri.ar(freq, env)      // Triangle wave
    ]);

    signal = Pan2.ar(wave, pan);
    OffsetOut.ar(0, signal);
}).add;
)

// Example of creating a grain with a randomly chosen waveform
Synth(\multiWaveGrain, [\freq, rrand(440, 1600), \waveform, rrand(0, 3)]);


(
Task({
    1000.do({
        Synth(\multiWaveGrain,
            [\freq, rrand(440, 1600),
             \amp, rrand(0.1, 0.3),
             \dur, rrand(0.02, 0.1),
             \waveform, rrand(0, 3).floor // Randomly select waveform
        ]);
        0.01.wait;
    });
}).start;
)

/////////////
// TRANSCHROME: the grain waveform evolves from one waveform to another
// over the duration of the cloud
//////////////

// Global variable to keep track of the waveform type
~waveformType = 0;

(
SynthDef(\evolvingWaveGrain, { arg freq=800, amp=0.4, dur=0.1, pan=0, waveform=0;
    var signal, env, wave;
    env = EnvGen.kr(Env.perc(0.01, dur, amp, -4), doneAction: 2);

    // Select waveform based on the global variable
    wave = Select.ar(waveform, [
        SinOsc.ar(freq, 0, env), // Sine wave
        Saw.ar(freq, env),       // Sawtooth wave
        Pulse.ar(freq, 0.5, env),// Square wave
        LFTri.ar(freq, env)      // Triangle wave
    ]);

    signal = Pan2.ar(wave, pan);
    OffsetOut.ar(0, signal);
}).add;
)

// Task to create a grain cloud with evolving waveform
(
Task({
    1000.do({ |i|
        Synth(\evolvingWaveGrain,
            [\freq, rrand(440, 1600),
             \amp, rrand(0.1, 0.3),
             \dur, rrand(0.02, 0.1),
             \waveform, ~waveformType
        ]);
        0.01.wait;

        // Gradually evolve the waveform type
        if (i % 100 == 0) {  // Change waveform type every 100 grains
            ~waveformType = (~waveformType + 1) % 4; // Cycle through 4 waveform types
        }
    });
}).start;
)
