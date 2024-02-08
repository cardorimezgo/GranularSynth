s.boot;

b = Buffer.read(s , "C:/Users/cardo/Documents/openFrameworks/apps/myApps/GranularSynth/Audio_Samples/Sound_Samples_668451__strangehorizon__zephy-people-act.wav");
b.play;

(
{
    var dur = 0.25; // Grain duration
    var density = 20; // Grains per second
    var bufferDur = BufDur.kr(b); // Duration of the buffer
    var signal, granulated, feedback, delayTime = 0.2, feedbackAmount = 0.2;

    // Use an LFO to modulate the position across the entire duration of the buffer
    var startPos = LFNoise1.kr(1).range(0, bufferDur);

    // Granular synthesis
    granulated = TGrains.ar(
        numChannels: 2,
        trigger: Impulse.kr(density),
        bufnum: b,
        dur: dur,
        pos: startPos,
        rate: 1,
        pan: LFNoise2.kr(0.5),
        amp: 0.5
    );

    // Feedback loop
    feedback = DelayN.ar(granulated, delayTime, delayTime);

    // Mix original granulated signal with feedback
    Mix.new([granulated, feedback * feedbackAmount])
}.play;
)