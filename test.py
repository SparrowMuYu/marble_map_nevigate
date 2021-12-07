import subprocess

lon = "-90.31"
lat = "38.65"
subprocess.run(["./build/521", lon, lat])
