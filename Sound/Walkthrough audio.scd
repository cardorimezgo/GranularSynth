s.boot

 /////// Sample Data ////////////////////////////////////////
////////////////////////////////////////////////////////////
(
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



//// //////////OSC_COM//////////////////////////////////////
/////////////////////////////////////////////////////////
m = NetAddr.new("127.0.0.1",12000); //listening to processing port 12000
//Variables to store the number of segments and chunk size
(
~numSegments = 0;
~chunkSize = 0;
~totalFrames = 0
)
///OSCdef to receive the number of segments and calculate the chunk size
(
OSCdef( 'listener', {|msg|
	~numSegments = msg[1].asInteger;
	"Number of segments received: %".format(~numSegments).postln;

{
		~totalFrames = b.numFrames;
		~chunkSize = (~totalFrames / ~numSegments).round;
		"Calculate chunk size: %" . format(~chunkSize).postln;
	}.defer;
}, "/num_segments");
)
OSCdef('listener').free;

////////////// Samples Management //////////////////////////////
//////////////////////////////////////////////////////////////
(
~createBufferArray = {
    var buffers = [];

    (0..~numSegments-1).do { |i|
        var startFrame = i * ~chunkSize;
        var newBuffer = Buffer.alloc(s, ~chunkSize);
        b.copyData(newBuffer, 0, startFrame, ~chunkSize);
        buffers = buffers.add(newBuffer);
    };

    buffers;
};
)

// Recreate the buffer array
~buffers = ~createBufferArray.value();


///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
// Define the SynthDef
(
SynthDef("playBuffer", { |out = 0, bufnum = 0, amp = 1|
    var source = PlayBuf.ar(1, bufnum, doneAction: Done.freeSelf);
    Out.ar(out, source * amp);
}).add;
)
// Function to play a specific chunk from the buffer array
(
~playChunk = { |index|
    if(index < 0 or: { index >= ~buffers.size }) {
        "Invalid index. Please choose an index between 0 and %.".format(~buffers.size - 1).postln;
    } {
        Synth("playBuffer", [\bufnum, ~buffers[index].bufnum]);
    };
};
)

// Example usage: play the first chunk (index 0)
~playChunk.(12);



(
SynthDef("playBuffer", { |out = 0, bufnum = 0, amp = 1, fadeInTime = 0.1, fadeOutTime = 0.1|
    var source = PlayBuf.ar(1, bufnum, doneAction: Done.freeSelf);
    var env = Env([0, 1, 1, 0], [fadeInTime, BufDur.kr(bufnum) - fadeInTime - fadeOutTime, fadeOutTime], curve: \linear);
    var fadeInOut = EnvGen.kr(env, doneAction: 2);
    Out.ar(out, source * amp * fadeInOut);
}).add;
)

// Define the ~playChunk function
(
~playChunk = { |index, amp = 1|
    if(index < 0 or: { index >= ~buffers.size }) {
        "Invalid buffer index.".postln;
    } {
        Synth("playBuffer", [
            \bufnum, ~buffers[index].bufnum,
            \amp, amp
        ]);
    };
};
)

(
~playConsecutiveChunks = { |startIndex, numberOfChunks, amp = 1, fadeInTime = 0.1, fadeOutTime = 0.1|
    if(startIndex < 0 or: { startIndex + numberOfChunks > ~buffers.size }) {
        "Invalid index or number of chunks. Please choose a valid range.".postln;
    } {
        (startIndex..(startIndex + numberOfChunks - 1)).do { |index|
            ~playChunk.(index, amp, fadeInTime, fadeOutTime);
            ((~chunkSize / s.sampleRate) - fadeOutTime).wait;  // Wait for the chunk to finish playing minus fade out time
        };
    };
};
)

fork { ~playConsecutiveChunks.(20, 100, 6, 0.09, 0.029); }
