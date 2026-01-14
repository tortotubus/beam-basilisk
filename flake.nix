{
  description = "Basilisk (CMake-wrapped, self-contained build)";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.11";

  outputs =
    { self, nixpkgs }:
    let
      systems = [
        "x86_64-linux"
        "aarch64-linux"
      ];
      forAllSystems = f: nixpkgs.lib.genAttrs systems (system: f system);
    in
    {
      # -----------------------------
      # 1. Packages (main Basilisk build)
      # -----------------------------
      packages = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.stdenv.mkDerivation {
            pname = "basilisk";
            version = "1.0.0";
            src = ./.; # your source tree with CMakeLists.txt

            nativeBuildInputs = with pkgs; [
              cmake
              gawk
              bison
              flex
            ];
            
            buildInputs = with pkgs; [
              zlib
              readline
              libpng
            ];

            configurePhase = ''
              cmake -S . -B build \
                -DCMAKE_BUILD_TYPE=Debug \
                -DCMAKE_INSTALL_PREFIX=$out
            '';

            # Build ONLY the targets you care about
            buildPhase = ''
              cmake --build build --target qcc
              # or multiple:
              # cmake --build build --target qcc bview2D bview3D bview2Dm
            '';

            installPhase = ''
              cmake --install build --component QCC
            '';

            strictDeps = true;

            cmakeFlags = [
              # tell CMake to use the correct prefix path
              "-DCMAKE_INSTALL_PREFIX=${placeholder "out"}"
              # ensure qcc knows where headers live
              "-DBASILISK=${placeholder "out"}/include/basilisk"
            ];

            meta = with pkgs.lib; {
              description = "Basilisk CFD framework (CMake-wrapped build)";
              homepage = "https://basilisk.fr";
              license = licenses.gpl3Plus;
              platforms = platforms.linux;
              maintainers = [ maintainers.yourname or "colive" ];
            };
          };
        }
      );

      # -----------------------------
      # 2. Developer shell (for local building)
      # -----------------------------
      devShells = forAllSystems (
        system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.mkShell {
            packages = with pkgs; [
              cmake
              ninja
              gawk
              bison
              flex
              zlib
              readline
              libpng
            ];
            shellHook = ''
              echo "🔧 Entered Basilisk dev shell"
              echo "   Run: cmake -B build -S . && cmake --build build"
            '';
          };
        }
      );
    };
}
