bye_bye_sources = [
  'main.c',
  'bye-bye-application.c',
  'bye-bye-window.c',
]

bye_bye_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1'),
]

bye_bye_sources += gnome.compile_resources('bye-bye-resources',
  'bye-bye.gresource.xml',
  c_name: 'bye_bye'
)

executable('bye-bye', bye_bye_sources,
  dependencies: bye_bye_deps,
       install: true,
)
