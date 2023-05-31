$curfile = Get-Content "currentlist.txt"
foreach ($line in $curfile){
	$Question = "what+is"
	Start-Process microsoft-edge:http://www.bing.com/search?q=$Question$line -WindowStyle Minimized
	start-sleep -Milliseconds 1500
}
start-sleep -Milliseconds 2000
Get-Process MicrosoftEdge | Foreach-Object { $_.CloseMainWindow() }
Write-Host done
Break Script