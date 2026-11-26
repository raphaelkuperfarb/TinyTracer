"""bmpdiff.py - compare two 24-bit BMP renders of the same size.

    python3 bmpdiff.py a.bmp b.bmp [diff.bmp] [-x N]

Prints how different they are and, if a third file is given, writes a diff image:
|a - b| per pixel, multiplied by N (default 8) so small differences show up.
Black = identical, brighter = more different.
"""
import struct
import sys


def load(path):
    d = open(path, 'rb').read()
    off = struct.unpack_from('<I', d, 10)[0]
    w, h = struct.unpack_from('<ii', d, 18)
    if struct.unpack_from('<H', d, 28)[0] != 24:
        sys.exit(f"{path}: only 24-bit BMP is supported")
    stride = (w * 3 + 3) & ~3
    px = bytearray()
    for y in range(abs(h)):
        px += d[off + y * stride: off + y * stride + w * 3]
    return w, h, px


def save(path, w, h, px):
    stride = (w * 3 + 3) & ~3
    pad = b'\0' * (stride - w * 3)
    rows = b''.join(bytes(px[y * w * 3:(y + 1) * w * 3]) + pad for y in range(abs(h)))
    header = struct.pack('<2sIHHI', b'BM', 54 + len(rows), 0, 0, 54)
    info = struct.pack('<IiiHHIIiiII', 40, w, h, 1, 24, 0, len(rows), 2835, 2835, 0, 0)
    open(path, 'wb').write(header + info + rows)


args = [a for a in sys.argv[1:] if not a.startswith('-x')]
scale = 8
for a in sys.argv[1:]:
    if a.startswith('-x'):
        scale = int(a[2:] or sys.argv[sys.argv.index(a) + 1])
args = [a for a in args if not a.isdigit()]
if len(args) < 2:
    sys.exit(__doc__)

wa, ha, a = load(args[0])
wb, hb, b = load(args[1])
if (wa, ha) != (wb, hb):
    sys.exit(f"sizes differ: {wa}x{abs(ha)} vs {wb}x{abs(hb)}")

diff = [abs(p - q) for p, q in zip(a, b)]
n = wa * abs(ha)
changed = sum(1 for i in range(0, len(diff), 3) if max(diff[i:i + 3]) > 0)
big = sum(1 for i in range(0, len(diff), 3) if max(diff[i:i + 3]) > 16)
print(f"mean difference      {sum(diff) / len(diff):.2f} (0-255 per channel)")
print(f"largest difference   {max(diff)}")
print(f"pixels that differ   {changed / n * 100:.1f}%")
print(f"pixels off by > 16   {big / n * 100:.1f}%")

if len(args) >= 3:
    save(args[2], wa, ha, bytearray(min(255, v * scale) for v in diff))
    print(f"wrote {args[2]} (differences x {scale})")
