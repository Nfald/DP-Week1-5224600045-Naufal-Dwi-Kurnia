# DP-Week1-5224600045-Naufal-Dwi-Kurnia

1. Apa struktur invariant dalam program Anda?
Struktur invariant yang ada dalam program yaitu alur utama yang dikendalikan oleh RunSession. Program selalu berjalan selama tiga ronde dan selalu mengikuti urutan phase yang sama, yaitu: menghasilkan input, menghitung base score, menghitung reward, memperbarui uang, menjalankan shop phase, lalu berpindah ke ronde berikutnya. Struktur tidak berubah meskipun beberapa aturan permainan dimodifikasi. Karena itu, RunSession merepresentasikan bagian program yang stabil atau tetap.

2. Bagian mana yang bersifat mutable?
Bagian mutable yaitu komponen yang perilakunya bisa diubah tanpa memengaruhi alur utama program. Dalam program saya, bagian tersebut adalah InputGenerator, ScoringRule, dan RewardRule. Sebagai contoh, cara menghasilkan input dapat diubah dari input tetap menjadi input acak, dan aturan perhitungan reward juga dapat diganti dengan aturan lain. Bagian-bagian ini fleksibel karena dipisahkan melalui interface.

3. Saat mengganti InputGenerator, mengapa RunSession tidak berubah?
RunSession tidak berubah karena ia hanya bergantung pada interface IInputGenerator, bukan pada implementasi tertentu. Selama generator baru tetap mengikuti interface yang sama, RunSession dapat menggunakannya dengan cara yang sama. Hal ini menunjukkan bahwa RunSession dirancang sebagai pengatur alur proses, sedangkan logika pembangkitan input diperlakukan sebagai komponen yang dapat diganti.

4. Apa yang akan terjadi jika logika scoring diletakkan di dalam RunSession?
Jika logika scoring diletakkan di dalam RunSession, maka RunSession tidak lagi menjadi orchestrator murni, yaitu mengatur jalannya proses atau alur. Ia akan menjadi sangat terikat pada satu aturan scoring tertentu, sehingga program menjadi lebih sulit untuk diubah dan dikembangkan. Setiap perubahan pada cara menghitung score akan memaksa kita mengubah RunSession, yang berarti memecah pemisahan antara invariant dan mutable parts. Akibatnya, desain menjadi kurang fleksibel dan lebih sulit dirawat.

# Reflection

Pada Task 1, saya belajar membedakan mana bagian program yang harus tetap dan mana bagian yang bisa diubah. Menurut saya, bagian yang paling jelas bersifat invariant adalah `RunSession`, karena class ini mengatur alur utama program dari awal sampai akhir. `RunSession` selalu menjalankan urutan phase yang sama, yaitu generate input, compute base score, compute reward, update money, shop phase, lalu advance round. Selain itu, jumlah ronde juga sudah ditentukan, yaitu tiga ronde. Bagi saya, inilah struktur inti dari program, karena urutan tersebut merupakan fondasi dari jalannya simulasi. Kalau urutan ini diubah, misalnya reward dihitung sebelum base score, maka alurnya menjadi tidak masuk akal dan hasil program bisa menjadi salah.

Sementara itu, bagian mutable dalam program ini adalah komponen-komponen yang bisa diganti tanpa merusak struktur utama. Dalam implementasi saya, bagian tersebut adalah `InputGenerator`, `ScoringRule`, dan `RewardRule`. Pada tahap awal, saya menggunakan input generator yang tetap dan aturan reward yang sederhana. Setelah itu, saya menggantinya dengan generator acak dan aturan reward baru. Hal yang penting adalah perubahan tersebut tidak membuat saya perlu mengubah `RunSession`. Menurut saya, ini menunjukkan bahwa pemisahan antara struktur utama dan logika detail sudah berjalan dengan baik.

Saya juga merasa bahwa desain seperti ini membuat program jauh lebih fleksibel. Jika suatu saat saya ingin menambahkan aturan scoring baru, sistem reward baru, atau jenis input yang berbeda, saya tidak perlu membongkar class utama. Saya hanya perlu membuat implementasi baru pada class yang memang bertanggung jawab untuk perilaku tersebut. Dengan begitu, program lebih mudah dikembangkan dan lebih mudah dirawat.

Kalau logika scoring atau reward diletakkan langsung di dalam `RunSession`, maka `RunSession` akan menjadi terlalu besar dan terlalu bergantung pada satu aturan tertentu. Akibatnya, setiap perubahan kecil akan memaksa saya mengedit class inti. Menurut saya, itu membuat program menjadi kurang rapi dan lebih sulit dikembangkan. Dari Task 1 ini, saya belajar bahwa menjaga `RunSession` tetap sebagai pengatur alur utama adalah hal yang penting agar program tetap modular, jelas, dan mudah diubah ketika ada kebutuhan baru.