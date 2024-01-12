https://github.com/qwertymodo/foo_input_msu

**All credit goes to qwertymodo! I just tweaked the implementation a little to allow for x64 compilation!**

# Installation

* Put foo_input_msu.dll in $FOOBAR_HOME\components\x64 (usually: C:\Program Files\foobar2000\components\x64)

# Building from source

* Install Microsoft Visual Studio Community 2022 (64-bit)
* Download the latest [foobar2000 SDK](http://www.foobar2000.org/SDK) and extract it to C:\foobar200sdk
* Check out this repository into its own folder, for instance: C:\foo_input_msu

![image](https://github.com/miguelmartins1987/foo_input_msu/assets/232489/9d12d53e-e6cf-4890-9535-ff7bfe4d6a18)

* Open the provided .sln file with Microsoft Visual Studio Community 2022
* Once all the projects are loaded, edit **C:\foobar2000sdk\foobar2000\SDK\playlist.h** within Visual Studio 2022, and add the following lines to the #include section:

```
#include <combaseapi.h>
#include <objidl.h>
```

It should look something like this:

![image](https://github.com/miguelmartins1987/foo_input_msu/assets/232489/a55cc9ee-5a2e-4993-a62d-db530fb85bf3)

* Build the solution
