// Ensure the server is booted before executing the rest of the script
s.waitForBoot {
    // Define the granular synthesis SynthDef
    SynthDef(\simpleGrain, {
        var freq = \freq.kr(440);
        var dur = \dur.kr(0.1);
        var amp = \amp.kr(0.1);
        var density = \density.kr(20);
        
        var env = Env.perc(0.01, dur, amp, -4);
        var trig = Impulse.kr(density);
        var grain = SinOsc.ar(freq) * EnvGen.kr(env, trig, doneAction: 2);
        
        Out.ar(0, grain ! 2); // Stereo output
    }).add;

    s.sync; // Wait for SynthDef to be added

    // Instantiate the granular synth
    x = Synth(\simpleGrain, [
        \freq, 440, // A4 note
        \dur, 0.1, // 100 ms grains
        \amp, 0.1, // Amplitude
        \density, 20 // 20 grains per second
    ]);

    // Schedule the Synth to stop after a delay
    SystemClock.sched(5, { arg time; x.free; "Synth stopped after 5 seconds.".postln; });
};
