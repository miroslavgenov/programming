$cpp = Read-Host "cpp file:";
$scpp = $cpp -split "\.";
$exc =$scpp[0];
g++ -o $exc $cpp
Invoke-Expression "./$exc.exe";
