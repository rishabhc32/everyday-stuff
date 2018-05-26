# hugo

### Generating hugo man pages
* `cd ~`
* `hugo gen man`
    * This will create `./man` directory, having hugo's manpages.
* `cd man`
* `gzip ./*`
* `sudo cp ./* /usr/share/man/man1/`
* `man hugo`, `man hugo-version`, `man hugo-gen`, ...

