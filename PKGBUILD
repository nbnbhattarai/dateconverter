# Maintainer : Nabin Bhattarai <nbn.bhattarai99@gmail.com>

pkgname=ndc
srcname=ndc
pkgver=1.0.0
pkgrel=1
pkgdesc="Nepali (BS) to English (AD) date converter and vice-versa utility."
arch=('any')
license=('GPL')
depends=('gcc','make')

build (){
    cd "$srcdir/$srcname-$pkgver"
    make
}

package(){
    cd "$srcdir/$srcname-$pkgver"
    make install
}
