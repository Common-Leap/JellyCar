![JellyCar logo](https://static.wikia.nocookie.net/jellycar/images/9/91/Jellycarlogo.png/revision/latest?cb=20231007222847)

## JellyCar is great 2d game with soft body physics created by Walaber https://twitter.com/walaber.

This is an updated version of the original project which updates the switch version to work on the latest version of atmosphere.


Current implemetation uses a modified version of [Andromeda-Lib](https://github.com/DrakonPL/Andromeda-Lib) which you patch from the original version before building

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
