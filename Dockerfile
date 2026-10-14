FROM nixos/nix:latest

WORKDIR /app

COPY flake.nix flake.lock .

COPY . .

RUN nix --extra-experimental-features "nix-command flakes" \
	develop .\#build --command make production

CMD ["./firmware"]
