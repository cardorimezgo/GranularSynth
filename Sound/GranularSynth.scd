s.boot
s.reboot;
s.plotTree;

//// //////////OSC_COM//////////////////////////////////////
/////////////////////////////////////////////////////////
//Receiving data
m = NetAddr.new("127.0.0.1",12000); //listening to processing port 12000
d = 1;
m.sendMsg("/rows:",d); //how to send a variable ?

//Sending data
NetAddr.localAddr // asking supercollider for listening port for OSC communication
(
OSCdef('listener',{
	Synth(\Sample_granular, [\bufnum, b.bufnum]);
}, "/rows"); //segment of the cloud played
)
//////////////////////////////////////////////////////////

( // Sample Data
b = Buffer.read(s,"E:/Interface/Audio/SuperCollider/AudioSamples/330961__tarikki__magnificat_mono.wav", action: { |buffer|
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
b.play;

////////////////// sample fragments //////////////////////////////////
(
SynthDef(\Sample_size, { |out = 0, bufnum = 0, amp = 0.4,  startFrame = 200000, endFrame = 425000|
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

////////////////// sample granular //////////////////////////////////
(
SynthDef(\Sample_granular, { |out = 0, bufnum = 0, amp = 0.1, startFrame = 200000, endFrame = 425000, grainDur = 10, numGrains = 50|
    var sound, env, sectionDur, trig;

    sectionDur = (endFrame - startFrame) / BufSampleRate.kr(bufnum);
    trig = Impulse.kr(numGrains / sectionDur * (1 + SinOsc.kr(0.5).range(0.5, 0.9)));

	//trig = Impulse.kr(numGrains / sectionDur);
    env = EnvGen.kr(Env.sine(sectionDur, amp), doneAction: 2);

    sound = GrainBuf.ar(1, trig, grainDur, bufnum, BufRateScale.kr(bufnum), startPos: startFrame, endPos: endFrame) ;
	//sound = GrainBuf.ar(1, trig, grainDur, bufnum, BufRateScale.kr(bufnum) * (1 + SinOsc.kr(0.1).range(0.5, 0.8)), startPos: startFrame, endPos: endFrame);

    Out.ar(out, sound);
}).add;
)

z = Synth(\Sample_granular, [\bufnum, b.bufnum, \startFrame, 200000, \endFrame, 425000]);
//////////////////////////////////////////////////////////////////


//////////////////Random Generation of Grains within sample
////////////////////////////////////////////////////////////
(
SynthDef(\Sample_granular, { |out = 0, bufnum = 0, amp = 0.5, startFrame = 000000, endFrame = 400000, grainDur = 10, numGrains = 50|
    var sound, env, sectionDur, trig;

    sectionDur = (endFrame - startFrame) / BufSampleRate.kr(bufnum);
    trig = Impulse.kr(numGrains / sectionDur);

    env = EnvGen.kr(Env.sine(sectionDur, amp), doneAction: 2);

    // Generate random start positions within the specified range
    sound = GrainBuf.ar(
        1,
        trig,
        grainDur * Rand(0.5, 5), // Random grain duration between 0.5 and 1.5 times the original duration
        bufnum,
        BufRateScale.kr(bufnum),
        startPos: TRand.kr(startFrame, endFrame, trig), // Random start position on each trigger
        endPos: endFrame
    );

    Out.ar(out, sound * amp);
}).add;
)

q = Synth(\Sample_granular, [\bufnum, b.bufnum, \startFrame, 000000, \endFrame, 200000]);









(
SynthDef(\Sample_size, { |out = 0, bufnum = 0, amp = 0.4, startFrame = 0, endFrame = 426491|
    var phasor, sound, env, sectionDur;
    sectionDur = (endFrame - startFrame) / BufSampleRate.kr(bufnum);
    env = EnvGen.kr(Env.sine(sectionDur , amp), doneAction:2);
    phasor = Phasor.ar(0, BufRateScale.kr(bufnum), startFrame, endFrame);
    sound = BufRd.ar(1, bufnum, phasor, 0);
    Out.ar(out, sound);
}).add;
)

(
var totalFrames = 426491;
var chunkSize = 1000;
var numberOfSteps = (totalFrames / chunkSize).round;
var chunkDuration = chunkSize / s.sampleRate;
var origDur = totalFrames / s.sampleRate;

Pbind(
    \instrument, \Sample_size,
    \bufnum, b.bufnum,
    \startFrame, Pseries(0, chunkSize, numberOfSteps),
    \endFrame, Pseries(chunkSize, chunkSize, numberOfSteps).collect { |val| val.min(totalFrames) },
    \dur, chunkDuration,
    \legato, chunkDuration / origDur,
).play;
)


///////// fragments segmented with fade in and out///////////
(
SynthDef(\Sample_size, { |out, bufnum, startFrame, endFrame, fadeInTime=0.0001, fadeOutTime=0.0001|
    var sig = PlayBuf.ar(1, bufnum, BufRateScale.kr(bufnum), startPos: startFrame, doneAction: Done.freeSelf);
    var env = EnvGen.kr(Env.linen(fadeInTime, (endFrame - startFrame) / s.sampleRate - fadeInTime - fadeOutTime, fadeOutTime), doneAction: Done.freeSelf);
    Out.ar(out, sig * env);
}).add;
)

(
var totalFrames = 426491;
var chunkSize = 1000;
var numberOfSteps = (totalFrames / chunkSize).round;
var chunkDuration = chunkSize / s.sampleRate;
var origDur = totalFrames / s.sampleRate;

Pbind(
    \instrument, \Sample_size,
    \bufnum, b.bufnum,
    \startFrame, Pseries(0, chunkSize, numberOfSteps),
    \endFrame, Pseries(chunkSize, chunkSize, numberOfSteps).collect { |val| val.min(totalFrames) },
    \dur, chunkDuration,
    \legato, chunkDuration / origDur,
).play;
)
//////////////////////////////////////////////////////
