s.boot
s.plotTree;

( // Sample Data
b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/668451__strangehorizon__zephy-people-act.wav", action: { |buffer|

	var numFrames = buffer.numFrames;
	var sampleRate = buffer.sampleRate;
	var duration = (numFrames / sampleRate); //Sample duration in minutes

	" numFrames: ".post;
	numFrames.post;
	",sampleRate: ".post;
	sampleRate.post;
	",Sample duration: ".post;
	duration.post;
	" seconds".post;
});
)

////////////////// sample fragments //////////////////////////////////
(
SynthDef(\Sample_size, { |out = 0, bufnum = 0, amp = 0.4,  startFrame = 500000, endFrame = 570000|
    var phasor, sound, env, sectionDur;
	sectionDur = (endFrame - startFrame) / BufSampleRate.kr(bufnum);
	env = EnvGen.kr(Env.sine(sectionDur , amp), doneAction:2); //doneAction:2
	phasor = Phasor.ar(0, BufRateScale.kr(bufnum), startFrame, endFrame);
    sound = BufRd.ar(1, bufnum, phasor, 0); // * env for fading in and out, no clicks and pops.
    Out.ar(out, sound);
}).add;
)

x = Synth(\Sample_size, [\bufnum, b.bufnum]);
///////////////////////////////////////////////////////////////////


(
SynthDef(\Sample_granular, { |out = 0, bufnum = 0, amp = 0.4, startFrame = 200000, endFrame = 235000, grainDur = 0.5, numGrains = 5|
    var sound, env, sectionDur, trig;

    sectionDur = (endFrame - startFrame) / BufSampleRate.kr(bufnum);
    trig = Impulse.kr(numGrains / sectionDur);
    env = EnvGen.kr(Env.sine(sectionDur, amp), doneAction: 2);

    sound = GrainBuf.ar(1, trig, grainDur, bufnum, BufRateScale.kr(bufnum), startPos: startFrame, endPos: endFrame) ;
    Out.ar(out, sound);
}).add;
)

z = Synth(\Sample_granular, [\bufnum, b.bufnum, \startFrame, 200000, \endFrame, 235000]);
