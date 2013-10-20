package emulator

import (
	"fmt"
	"image"
	"image/color"
	"image/png"
	"os"
)

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

	W = int(width)
	H = int(height)
	Screen = image.NewRGBA(image.Rect(0, 0, W, H))
}

var (
	Screen     *image.RGBA
	W, H       int
	scrotcount int
)

const (
	R = 1<<15 + 1<<14 + 1<<13 + 1<<12 + 1<<11
	G = 1<<10 + 1<<9 + 1<<8 + 1<<7 + 1<<6 + 1<<5
	B = 1<<4 + 1<<3 + 1<<2 + 1<<1 + 1<<0
)

func Scrot() {
	FB := FrameBufferInfo.pointer
	for y := 0; y < H; y++ {
		for x := 0; x < W; x++ {
			pix := FB[y*W+x]
			r := uint8(pix & R >> 8)
			g := uint8(pix & G >> 3)
			b := uint8(pix & B << 3)
			col := color.NRGBA{r, g, b, 255}
			Screen.Set(x, y, col)
		}
	}

	fname := fmt.Sprintf("%06d.png", scrotcount)
	scrotcount++
	f, err := os.OpenFile(fname, os.O_CREATE|os.O_TRUNC|os.O_WRONLY, 0666)
	assert(err == nil)
	defer f.Close()
	png.Encode(f, Screen)
}

func assert(test bool) {
	if !test {
		panic("assertion failed")
	}
}
