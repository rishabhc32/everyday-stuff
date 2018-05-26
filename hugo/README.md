# hugo

### Generating hugo man pages
`hugo`, when installed via `snap` does not provide manpages. So, we have to generate them ourselves.
* `cd ~`
* `hugo gen man`
    * This will create `./man` directory, having hugo's manpages.
* `cd man`
* `gzip ./*`
* `sudo cp ./* /usr/share/man/man1/`
* `man hugo`, `man hugo-server`, `man hugo-gen`, ...

