# User keymap for the M1 V5 keyboard

This keymap is better used with the firmware from: <https://github.com//xethlyx/qmk_firmware>

To setup the environment, configure with:

```sh
sudo apt install -y git python3-pip
curl -LsSf https://astral.sh/uv/install.sh | sh

uv tool install qmk

mkdir -p ~/repos
qmk setup

# To setup the custom firmware from separate repo, use:
qmk config user.qmk_home=$HOME/repos/qmk_firmware_m1v5
qmk setup xethlyx/qmk_firmware --baseurl https://github.com/ --branch wireless

# Then config the user overlay
git clone https://github.com/carlosedp/qmk_userspace.git ~/repos/qmk_userspace
qmk config user.overlay_dir="$(realpath ~/repos/qmk_userspace)"

# To build, do:
qmk compile -kb monsgeek/m1_v5/m1_v5_us -km carlosedp
```

References:

- <https://docs.qmk.fm/newbs_getting_started>
- <https://docs.astral.sh/uv/>
