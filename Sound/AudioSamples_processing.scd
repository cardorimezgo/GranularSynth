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
NetAddr.localAddr // asking supercollider for listening port for

// Update the number of segments when receiving an OSC message from Processing
(
OSCdef('listener', {|msg|
    var num_segments = msg[1].asInteger;
    "Number of segments received: %".format(num_segments).postln;

    {
        var totalFrames = b.numFrames;
        var chunkSize = (totalFrames / num_segments).round;
        "Calculated chunk size: %".format(chunkSize).postln;
    }.defer;
}, "/num_segments");
)

OSCdef('listener').free;  //disable OSC communication

//////////////////////////////////////////////////////////
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


///////// fragments segmented with fade in and out///////////
(
SynthDef(\Sample_size, { |out, bufnum, startFrame, endFrame, fadeInTime=0.0001, fadeOutTime=0.0001|
    var sig = PlayBuf.ar(1, bufnum, BufRateScale.kr(bufnum), startPos: startFrame, doneAction: Done.freeSelf);
    var env = EnvGen.kr(Env.linen(fadeInTime, (endFrame - startFrame) / s.sampleRate - fadeInTime - fadeOutTime, fadeOutTime), doneAction: Done.freeSelf);
    Out.ar(out, sig * env);
}).add;
)

(
var totalFrames = b.numFrames;
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

