package main

type FrameBuferDescription struct {
	width    uint32
	height   uint32
	vWidth   uint32
	vHeight  uint32
	pitch    uint32
	bitDepth uint32
	x        uint32
	y        uint32
	pointer  []uint16
	size     uint32
}

var FrameBufferInfo FrameBuferDescription

const PIXBYTES = 2 // 16 bit

func InitialiseFrameBuffer(width, height, bitDepth uint32) {
	assert(bitDepth == 16)
	FrameBufferInfo.width = width
	FrameBufferInfo.height = height
	FrameBufferInfo.vWidth = width
	FrameBufferInfo.vHeight = height
	FrameBufferInfo.pitch = PIXBYTES * width
	FrameBufferInfo.bitDepth = bitDepth
	FrameBufferInfo.x = 0
	FrameBufferInfo.y = 0
	FrameBufferInfo.pointer = make([]uint16, width*height)
	FrameBufferInfo.size = width * height * PIXBYTES
}

func assert(test bool) {
	if !test {
		panic("assertion failed")
	}
}

func main() {

}
