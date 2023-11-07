# Lawndon Lite

Before turning Lawndon into an autonomous mower, the first step is to create a remote controlled mower which can tackle any terrain. This can be accomplished by recycling any "outdated" electric mower you can find, I found a suitable [24v Worx mower](https://www.worx.com/24v-cordless-lawn-mower-wg782.html) which someone was throwing out. Eventually, I would like to construct a complete build for Lawndon that is reproducable by anyone with a 3d printer.

The main idea is to have a high torque, low power mower to be efficient and powerful enough to climb hills. In order to acheive this I used 2 [360KV brushless motors](https://www.rctimer.com/rctimer-5010-360kv-multicopter-brushless-motor-p0233.html) to power a 56:1 gearbox that is attached to tracks. The gears and tracks are based on [Rctestflight's Snowcat design](https://www.thingiverse.com/thing:4308626).

## Prerequisites

- 3D printer
- Electric mower
- Remote controller
- Receiver
- Arduino Mega

## Materials

- 2X 5010 Brushless Motor 360KV 2-6S
- 2X 14.8V 4S [LiPo batteries](https://www.racedayquads.com/products/rdq-series-14-8v-4s-1500mah-100c-lipo-battery-3-pack-xt60?variant=21554953420913)
- 4X 8mm diameter hardened steel linear bearing rod, 400mm long ea
- 4X 4mm Steel Rods (gearbox axles)
  - 95mm and 80mm 
- 12X F694zz Flanged Ball Bearings (4mm*11mm*4mm)
- 503 MUSIC WIRE .055 X 36IN 
  - 100mm segments, 35 segments per track
  - 8 pieces of 36” wire total
- 4X M3*12mm 304 stainless steel Hex Hexagon Socket Cap Head Self-tapping Screw 
- 4X M3*16mm 304 stainless steel Hex Hexagon Socket Cap Head Self-tapping Screw
- 16X 22*8*7 skateboard bearings 
- 2X 30A Brushless [ESCs](https://www.amazon.com/RC-Brushless-Electric-Controller-bullet/dp/B071GRSFBD)
- 8X M3X8mm Flat head
- 8X M3X18mm Flat head screws
- 16X M3X25mm screws
- 16X M3 Lock Nuts
- 4-5kg PLA

### Print Settings
- 0.8mm Nozzle
- 2 line wall thickness 
- 0.35mm or 0.4mm layer height 
- 30-40% infill for the stuff that needs to be strong like tracks and gears. 15-20% for everything else.
