# Maintainer : Nabin Bhattarai <nbn.bhattarai99@gmail.com>

pkgname=ndc-git
srcname=ndc
pkgver=1.0.0
pkgrel=1
pkgdesc="Nepali (BS) - English (AD) date converter utility."
url=("https://github.com/nbnbhattarai/dateconverter")
arch=('any')
license=('GPL')
depends=('gcc' 'make')
md5sums=('SKIP')
#source=($pkgname-$pkgver.tar.gz)
source=("$pkgname::https://github.com/nbnbhattarai/dateconverter.git")

build (){
    #cd "$pkgname-$pkgver"
    make
}

package(){
    #cd "$pkgname-$pkgver"
    make install
}
