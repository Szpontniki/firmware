{
	description = "C++ Development Environment";

	inputs = {
		nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
	};

	outputs = { self, nixpkgs }:
		let
			system = "x86_64-linux"; # Adjust if using a different architecture.
			pkgs = import nixpkgs { inherit system; };

			# Parts of the dev shell shared between build and default, development environment.
			common = {
				packages = with pkgs; [
					gcc
					gnumake
					pkg-config
					notcurses
					crow
				];
				environment = {
					CROW_INCLUDE = "${pkgs.crow}/include";
				};
			};
		in
		{
			devShells.${system} = {
				default = pkgs.mkShell (common.environment // {
					packages = common.packages ++ (with pkgs; [
						# Tooling.
						platformio
						bear
						docker
					]);
				});

				build = pkgs.mkShell (common.environment // {
					packages = common.packages;
				});
			};
		};
}
