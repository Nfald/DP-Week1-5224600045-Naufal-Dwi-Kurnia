# DP-Week1-5224600045-Naufal-Dwi-Kurnia

1. Apa struktur invariant dalam program Anda?
Struktur invariant yang ada dalam program yaitu alur utama yang dikendalikan oleh RunSession. Program selalu berjalan selama tiga ronde dan selalu mengikuti urutan phase yang sama, yaitu: menghasilkan input, menghitung base score, menghitung reward, memperbarui uang, menjalankan shop phase, lalu berpindah ke ronde berikutnya. Struktur tidak berubah meskipun beberapa aturan permainan dimodifikasi. Karena itu, RunSession merepresentasikan bagian program yang stabil atau tetap.

2. Bagian mana yang bersifat mutable?
Bagian mutable yaitu komponen yang perilakunya bisa diubah tanpa memengaruhi alur utama program. Dalam program saya, bagian tersebut adalah InputGenerator, ScoringRule, dan RewardRule. Sebagai contoh, cara menghasilkan input dapat diubah dari input tetap menjadi input acak, dan aturan perhitungan reward juga dapat diganti dengan aturan lain. Bagian-bagian ini fleksibel karena dipisahkan melalui interface.

3. Saat mengganti InputGenerator, mengapa RunSession tidak berubah?
RunSession tidak berubah karena ia hanya bergantung pada interface IInputGenerator, bukan pada implementasi tertentu. Selama generator baru tetap mengikuti interface yang sama, RunSession dapat menggunakannya dengan cara yang sama. Hal ini menunjukkan bahwa RunSession dirancang sebagai pengatur alur proses, sedangkan logika pembangkitan input diperlakukan sebagai komponen yang dapat diganti.

4. Apa yang akan terjadi jika logika scoring diletakkan di dalam RunSession?
Jika logika scoring diletakkan di dalam RunSession, maka RunSession tidak lagi menjadi orchestrator murni, yaitu mengatur jalannya proses atau alur. Ia akan menjadi sangat terikat pada satu aturan scoring tertentu, sehingga program menjadi lebih sulit untuk diubah dan dikembangkan. Setiap perubahan pada cara menghitung score akan memaksa kita mengubah RunSession, yang berarti memecah pemisahan antara invariant dan mutable parts. Akibatnya, desain menjadi kurang fleksibel dan lebih sulit dirawat.