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
~numSegments = 0;
~chunkSize = 0;
~totalFrames = 0
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
        buffers = buffers.add(Buffer.alloc(s, ~chunkSize));
    };

    buffers;
};
)

~buffers = ~createBufferArray.value();  // Change the number 5 to the desired number of segments

~buffers.do(_.free);
