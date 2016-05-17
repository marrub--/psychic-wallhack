param(
   [switch] $no_output,
   [switch] $check,
   [string] $fname
)

$uagent = "Mozilla/5.0 (Windows NT 6.2; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.94 Safari/537.36"
$progressPreference = 'silentlyContinue'

foreach($line in [System.IO.File]::ReadLines($fname))
{
   $outf = "output/" + ($line -split '/')[-1].split(':')[0]
   
   if(test-path $outf) {
      continue
   }
   
   if($line -contains "pixiv") {
      $head = @{"Referer" = "http://i1.pixiv.net/"}
   } else {
      $head = @{}
   }
   
   echo "Getting $line"
   
   try
   {
      if($no_output -or $check) {
         $r = Invoke-WebRequest -useragent $uagent -header $head -uri $line -sessionvariable ofp -erroraction stop -timeout 60
      }
      else
      {
         echo "Output: $outf"
         $r = Invoke-WebRequest -useragent $uagent -header $head -uri $line -sessionvariable ofp -erroraction stop -timeout 60 -outfile $outf
      }
   }
   catch
   {
      echo $r
      echo $line | out-file -append failed_links.txt
      continue
   }
   
   if($check)
   {
      if(-not (test-path $outf)) {
         $line | out-file -append nonexisting_links.txt
      }
   }
}

