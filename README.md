# oe2-tdsp-toolchain

Toolchain for running Simulink models on the HiFi 3z DSP (ADAU1860) of the OpenEarable 2.0.
Firmware: [emre227/open-earable-2](https://github.com/emre227/open-earable-2), branch `tdsp_driver`.

## Flow

1. Generate code from the Simulink model (`matlab/models`) with Embedded Coder (*Generate code only*)
2. Copy the generated code into `tdsp/tdsp_hw`
3. Build `tdsp_hw` (target *Deploy*) in Xtensa Xplorer
4. Run `matlab/scripts/gen_lark_tdsp_script.m`, this creates `output/Lark-tdsp.c`
5. Copy `Lark-tdsp.c` into the firmware, build and flash. The nRF5340 loads the image into the DSP at boot.

## Requirements

- MATLAB/Simulink R2025a with Embedded Coder and Fixed-Point Designer
- Xtensa Xplorer 9.0.20, XtensaTools RI-2022.10, core config `hifi3z_lark_RI_2022_10`
- LSP `adau-tdsp`: copy `lsp/adau-tdsp` to
  `<XtDevTools>/install/builds/RI-2022.10-win32/hifi3z_lark_RI_2022_10/xtensa-elf/lib/`
  and run `xt-genldscripts --xtensa-core=hifi3z_lark_RI_2022_10 -b .` in that folder
- `xt-objcopy` on the PATH

## HRIR data

- CIPIC HRTF Database, HUTUBS HRTF Database