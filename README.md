
![JellyCar logo](https://marcinp.xyz/jellycar/2020031417273500-DB1426D1DFD034027CECDE9C2DD914B8.jpg)

## JellyCar is great 2d game with soft body physics created by Walaber https://twitter.com/walaber.

This is homebrew version that I made with permission from original author for many platforms.
(PC, PSP, Wii,PlayStation 3, PlayStation Vita, Nintendo Switch)


Current implemetation uses my library: [Andromeda-Lib](https://github.com/DrakonPL/Andromeda-Lib)

## Build instructions

### Nintendo Switch

1. Clone both repositories as siblings:

```sh
git clone https://github.com/DrakonPL/Andromeda-Lib
git clone https://github.com/Common-Leap/JellyCar.git JellyCar
```

Expected layout:

```txt
Workspace/
  Andromeda-Lib/
  JellyCar/
```

Run the remaining commands from the `Workspace/` directory shown above.

2. Install devkitPro + Switch toolchain and libs:

```sh
sudo pacman -Syu devkitA64 libnx switch-tools \
  switch-pkg-config switch-mesa switch-glad switch-glm \
  switch-sdl2 switch-sdl2_mixer switch-freetype switch-harfbuzz
```

3. Set environment variables:

```sh
export DEVKITPRO=/opt/devkitpro
export DEVKITA64=$DEVKITPRO/devkitA64
export PATH=$DEVKITA64/bin:$DEVKITPRO/tools/bin:$DEVKITPRO/portlibs/switch/bin:$PATH
```

4. Apply the required `Andromeda-Lib` compatibility patch for latest `libnx`:

```sh
git -C Andromeda-Lib apply ../JellyCar/Build/Switch/andromeda-lib-libnx.patch
```

5. Build:

```sh
cd JellyCar/Build/Switch
make -j$(nproc)
```

If `Andromeda-Lib` is not in the default sibling location:

```sh
make -j$(nproc) ANDROMEDA_LIB=/absolute/or/relative/path/to/Andromeda-Lib
```
