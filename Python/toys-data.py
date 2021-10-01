# Judul Aplikasi
print("")
print("                             Toko Mainan Anak                                 ")
print("                 *****************************************                    ")
print("")

# Masukan Data Pembelian
namaPembeli = str(input("Masukan Nama Pembeli   : "))
kodeMainan  = str(input("Masukan Kode Mainan    : "))
hargaMainan = int(input("Masukan Harga          : "))
jumlahBeli  = int(input("Masukan Jumlah Beli    : "))
totalBayar  = hargaMainan * jumlahBeli

# Pembatas Tampilan
print("")
print("==============================================")
print("")

# Cetak Hasil Input Data Pembelian
print("Nama Pembeli     =", namaPembeli)
print("Kode Mainan      =", kodeMainan)
print("Harga            =", hargaMainan)
print("Jumlah Beli      =", jumlahBeli)
print("Total            =", totalBayar)
print("")
