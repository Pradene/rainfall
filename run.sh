#!/bin/bash

IMAGE="rainfall.qcow2"
ISO="rainfall.iso"
ISO_URL="https://cdn.intra.42.fr/isos/RainFall.iso"
IMAGE_SIZE="2G"

if [ ! -f "$IMAGE" ]; then
    echo "[+] Creating $IMAGE ($IMAGE_SIZE)"
    qemu-img create -f qcow2 "$IMAGE" "$IMAGE_SIZE"
else
    echo "[=] $IMAGE already created"
fi

if [ ! -f "$ISO" ]; then
    echo "[+] Downloading $ISO"
    wget "$ISO_URL" -O "$ISO"
else
    echo "[=] $ISO already downloaded"
fi

qemu-system-x86_64 \
    -m 1024 \
    -hda "$IMAGE" \
    -cdrom "$ISO" \
    -boot d \
    -enable-kvm \
    -net nic \
    -net user,hostfwd=tcp::4243-:4242 \
    -daemonize
