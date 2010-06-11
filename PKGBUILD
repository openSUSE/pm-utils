pkgname=pm-utils-git
pkgver=$(date +%s)
pkgrel=$(git log --pretty=format:%h |head -n 1)
pkgdesc="Utilities and scripts for suspend and hibernate power management"
arch=('i686' 'x86_64')
url="http://pm-utils.freedesktop.org"
license=('GPL')
conflicts=('pm-utils')
provides=('pm-utils=9999')
depends=('bash' 'procps' 'vbetool' 'pm-quirks')
optdepends=('upower')
makedepends=('xmlto' 'docbook-xml' 'docbook-xsl' 'git')
source=()
md5sums=()

build() {
   cd ..
  ./autogen.sh
  ./configure --prefix=/usr \
              --sysconfdir=/etc \
              --localstatedir=/var || return 1
  make || return 1
  make DESTDIR="${pkgdir}" install || return 1
}