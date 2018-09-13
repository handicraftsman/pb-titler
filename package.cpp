#include <particlepm.hpp>

using namespace PPM::Utils;

PPM_PACKAGE(p) {
  p->name("pb-titler");
  p->version(PPM::Version("v0.1.0"));
  p->description("A titler plugin for PositronBot");
  p->github(PPM::GitHub("handicraftsman", "pb-titler"));
  p->license(PPM::License("MIT", "https://github.com/handicraftsman/pb-titler/blob/master/LICENSE.txt"));

  PPM::GitHubPtr 
    pb_d    = p->github_repo("handicraftsman", "positronbot"),
    pdi_d   = p->github_repo("handicraftsman", "particledi"),
    pini_d  = p->github_repo("handicraftsman", "particleini"),
    guosh_d = p->github_repo("handicraftsman", "guosh");

  std::string curlflags = p->pkgconfig("libcurl");
  std::string xmlflags  = p->pkgconfig("libxml++-2.6");

  std::vector<std::string> src {
    "main.cpp"
  };

  std::string flags = flagcat({
    ("-L" + PPM::dist_dir),

    "-lpositronbot",
    "-lparticledi",
    "-lparticleini",
    "-lguosh",

    "-I.",
    ("-I" + pb_d->dir()),
    ("-I" + pdi_d->dir()),
    ("-I" + pini_d->dir()),
    ("-I" + guosh_d->dir() + "/src"),

    curlflags,
    xmlflags
  });

  PPM::TargetPtr plugin = p->library("pb-titler");
  plugin->cpp("gnu++17");
  plugin->cpp_files(src);
  plugin->cpp_flags(flags);
}