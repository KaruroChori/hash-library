project('hashlib', 'cpp', version: '1.0.0')

src = files(
    './src/crc32.cpp',
    './src/digest.cpp',
    './src/keccak.cpp',
    './src/md5.cpp',
    './src/sha1.cpp',
    './src/sha256.cpp',
    './src/sha3.cpp',
    './src/murmur3.cpp'
)

include_dir = include_directories('./include')

hashlib = library(
    'hashlib',
    src,
    include_directories: [include_dir],
    install: not meson.is_subproject(),
    override_options : ['cpp_std=c++20']
)

hashlib_dep = declare_dependency(
    include_directories: include_dir,
    link_with: hashlib,
)

pkg_mod = import('pkgconfig')

pkg_mod.generate(
    hashlib,
    name: 'hashlib',
    description: 'Portable C++ hashing library',
    libraries: hashlib,
    version: meson.project_version(),
)

subdir('./test')