Dim s, FSO,F,SFold,SubFolders,Folder, TextStream
' Выводим строку на экран
do
WScript.StdOut.WriteLine "Menu:"
WScript.StdOut.WriteLine "----------------------------"
WScript.StdOut.WriteLine "1. Author Information"
WScript.StdOut.WriteLine "2. Folder archiving"
WScript.StdOut.WriteLine "3. Saving in a text file a list of folders in a given directory"
WScript.StdOut.WriteLine "4. Exit"
WScript.StdOut.Write "Select a menu item:"
' Считываем строку
s = WScript.StdIn.ReadLine
' Создаем объект WshShell
Set WshShell = WScript.CreateObject("WScript.Shell")
if (s="1") Then
WScript.StdOut.WriteLine "Shcherbenko Maksim Anatolievich, ITI-11"
elseif(s="2") Then
WScript.StdOut.Write "Enter filename:"
 f = WScript.StdIn.ReadLine
' Запускаем командный файл и ожидаем окончания ее работы
Set WshShell = CreateObject("WScript.Shell")

WshShell.Run ("""C:\Program Files\WinRAR\Rar.exe"" a ""H:\arc.rar"" -r ""H:\" & f & """")




elseif(s="3") Then
WScript.StdOut.Write "Enter directory path:"
 f = WScript.StdIn.ReadLine
 'Объявляем переменные
'Создаем объект FileSystemObject
Set FSO = WScript.CreateObject("Scripting.FileSystemObject")
'Путь к каталогу
SFold = "E:\" & f & ""
s = "Каталог " & SFold & VbCrLf
s = s & "Подкаталоги:" & VbCrLf
'Создаем объект Folder для каталога C:\Program Files
Set F=FSO.GetFolder(SFold)
'Создаем коллекцию подкаталогов каталога C:\Program Files
Set SubFolders = F.SubFolders
'Цикл по всем подкаталогам
For Each Folder In SubFolders
 'Добавляем строку с именем подкаталога
 s = s & Folder & VbCrLf
Next

' Инициализируем константы
Const ForReading = 1, ForWriting = 2, TristateUseDefault = -2
' Создаем объект FileSystemObject
Set FSO=WScript.CreateObject("Scripting.FileSystemObject")
' Создаем в текущем каталоге файл test1.txt
FSO.CreateTextFile "test1.txt"
' Создаем объект File для файла test1.txt
set F=FSO.GetFile("E:\test1.txt")
' Создаем объект TextStream (файл открывается для записи)
Set TextStream=F.OpenAsTextStream(ForWriting, TristateUseDefault)
' Записываем в файл строку
TextStream.WriteLine s
' Закрываем файл
TextStream.Close

End if
loop until (s="4")