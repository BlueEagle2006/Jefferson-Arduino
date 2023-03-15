# Jefferson Cryptography Device
This project is the first project where I used C++ to program an Arduino Uno. It is basically a device that can encrypt and decrypt given string values using a cypher which is named after Thomas Jefferson. This cypher works by having more than one disks which have the alphabet on them. But the order of the letters in the alphabet are basically shuffled so every disk has a different order of letters (like below).

<img src="https://user-images.githubusercontent.com/68196837/225085024-6f230348-49fe-439e-91e8-eb58a95efa20.png" width="500"></img>

So if we want to encrypt the word "VATAN" which means "homeland" in Turkish. We need to find the corresponding letters and mark them green. After this process the encrypted version of the text becomes the letters which are marked red (we slide one letter to the right). So we get the text "ICEOZ" as the encryption and can slide one letter to the left this time to get the original decrypted text. One point where I want you to realize is that the original string had two "A"'s in it. When we encrypted it these two letters matched with the letters "C" and "O". This is where people who may try to crack the cypher start to having trouble because if they try to use a cryptanalysis method called [Frequency analysis](https://en.wikipedia.org/wiki/Frequency_analysis) where they guess the encrypted letter considering the usage rate of it in the encrypted text. Well it turns out you can't do that with Jefferson since same two letters such as two "A"'s may turn into two very different letters.

# The Device

Actually there are two devices that I created to do the exact same process. The first had it's input provided to it by a potentiometer and a button which can be seen below and it didn't have any option to delete (modify) the input text on the screen. It had many more issues thou one of which since I couldn't solder the jumper cables to the Arduino (I didn't have the required resources and wanted to use the Arduino again in the future) they fell off from their ports very often and since the Arduino was put inside a box it was frustrating to reasemble the jumpers into the right port.

<img src="https://user-images.githubusercontent.com/68196837/225093170-b4f02605-812e-4c79-90b0-5cc27a6016a4.png" height="250"></img>
<img src="https://user-images.githubusercontent.com/68196837/225093527-37bd92cb-d20a-4f4a-af90-a0bf36a67360.png" height="250"></img>
> First Prototype

So I made a new one using a setup as simple as shown bellow, with an LCD Shield which had plenty of buttuns on it so I could finally edit the input text.

<img src="https://user-images.githubusercontent.com/68196837/225094395-c5e924c3-e2f2-472b-acbc-645ef4348541.png" height="300"></img>
<img src="https://user-images.githubusercontent.com/68196837/225094552-e6e487f6-01d9-4b4c-8357-1f4deaedc918.png" height="300"></img>
> Final Device Setup

* I added the project report pdf alongside the code.
