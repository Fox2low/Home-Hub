const char settings_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<style>
    body, h1, h2, h3, p, ul, li {
        margin: 0;
        padding: 0;
      }
      
      body {
        font-family: Arial, sans-serif;
      }
      
      header {
        background-color: #222;
        color: #fff;
        text-align: center;
        padding: 1rem;
      }
      
      .logo img {
        width: 60px;
        height: 60px;
        margin-bottom: 10px;
      }
      
            /* Nav Bar */
            nav {
              background-color: #444;
              padding: 0.5rem;
              display: flex;
              justify-content: space-between;
              align-items: center;
            }
            
            .nav-list {
              list-style: none;
              display: flex;
              justify-content: center;
              margin-right: auto;
            }
            
            .nav-list li {
              margin-right: 1rem;
            }
            
            .nav-list a {
              color: #fff;
              text-decoration: none;
              padding: 0.5rem 1rem;
              border-radius: 5px;
            }
            
            .nav-list a:hover {
              background-color: #666;
            }
            
            .menu-toggle {
              display: none;
              flex-direction: column;
              cursor: pointer;
              z-index: 2;
              position: relative;
            }
            
            .menu-toggle .bar {
              width: 25px;
              height: 3px;
              background-color: white;
              margin: 2px 0;
            }
            
            @media (max-width: 768px) {
              .nav-list {
                display: none;
                flex-direction: column;
                align-items: center;
                width: 100%;
                position: absolute;
                background-color: #333;
                top: 60px;
                left: 0;
                transition: transform 0.3s ease-in-out;
                transform: translateX(-100%);
              }
            
              .nav-list.active {
                transform: translateX(0);
                display: flex;
              }
            
              .menu-toggle {
                display: flex;
              }
            
              .close-button {
                display: none;
                cursor: pointer;
                position: absolute;
                top: 10px;
                right: 10px;
                z-index: 1;
              }
            
              .nav-list.active + .close-button {
                display: block;
              }
            }
            /* Nav Bar End */
      
      main {
        display: grid;
        grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
        gap: 1rem;
        padding: 1rem;
      }
      
      .device-card {
        background-color: #f0f0f0;
        padding: 1rem;
        border-radius: 10px;
        box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
      }
      
      .control-panel {
        background-color: #f7f7f7;
        padding: 1rem;
        text-align: center;
        margin-top: 2rem;
      }
      
      footer {
        background-color: #333;
        color: #fff;
        text-align: center;
        padding: 0.5rem;
      }
      
      .switch {
        position: relative;
        display: inline-block;
        width: 60px;
        height: 34px;
      }
      
      .switch input {
        opacity: 0;
        width: 0;
        height: 0;
      }
      
      .slider {
        position: absolute;
        cursor: pointer;
        top: 0;
        left: 0;
        right: 0;
        bottom: 0;
        background-color: #ccc;
        -webkit-transition: .4s;
        transition: .4s;
        border-radius: 34px;
      }
      
      .slider:before {
        position: absolute;
        content: "";
        height: 26px;
        width: 26px;
        left: 4px;
        bottom: 4px;
        background-color: white;
        -webkit-transition: .4s;
        transition: .4s;
        border-radius: 50%;
      }
      
      input:checked + .slider {
        background-color: #2196F3;
      }
      
      input:focus + .slider {
        box-shadow: 0 0 1px #2196F3;
      }
      
      input:checked + .slider:before {
        -webkit-transform: translateX(26px);
        -ms-transform: translateX(26px);
        transform: translateX(26px);
      }    

      form label {
        display: inline-block;
        width: 100px;
      }
      
      form input[type="text"],
      form input[type="password"] {
        width: auto;
        padding: 12px 20px;
        margin: 8px 0;
        display: inline-block;
        border: 1px solid #ccc;
        border-radius: 4px;
        box-sizing: border-box;
      }
      
      form br {
        display: block;
        margin: 10px 0;
      }
      
      input[type=submit] {
        width: auto;
        background-color: #4CAF50;
        color: white;
        padding: 14px 20px;
        margin: 8px 0;
        border: none;
        border-radius: 4px;
        cursor: pointer;
      }
      
      input[type=submit]:hover {
        background-color: #45a049;
      }
</style>

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Smart Home Hub</title>
</head>

<body>
  <header>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <div class="logo">
      <h1>Smart Home Hub</h1>
    </div>
  </header>
  <!-- Nav Bar -->
  <nav>
    <div class="menu-toggle" onclick="toggleNav()">
      <div class="bar"></div>
      <div class="bar"></div>
      <div class="bar"></div>
    </div>
    <ul class="nav-list" id="navList">
      <li><a href="/">Home</a></li>
      <li><a href="settings">Settings</a></li>
      <li><a href="hub">Hub</a></li>
      <li><a href="actions">Actions</a></li>
      <li><a href="network">Network</a></li>
      <li><a href="graphs">Graphs</a></li>
    </ul>
    <div class="close-button" onclick="toggleNav()"></div>
  </nav>
  <!-- Nav Bar end-->

  <main>
    <div class="device-card">
      <h2>Wifi-Setup</h2>
      <p>Connect to home wifi</p><br>
        <form id="Wifi">
            <label for="fname">SSID:</label>
            <input type="text" id="SSID" name="SSID" required><br><br>
            <label for="fname">Password:</label>
            <input type="password" id="Pass" name="Pass" required><br><br>
            <label for="fname">IP Address:</label>
            <input type="text", id="IP" name ="IP" placeholder="Optional"><br><br>
            <label for="fname">Subnet:</label>
            <input type="text", id="Subnet" name ="Subnet" placeholder="Optional"><br><br>
            <input type="submit">  
        </form>
        <p><em>Warning: Connecting this device to the wifi means that you won't be able to access the device through this URL</em></p>
    </div>
    <div class="device-card">
        <h2>Device-Setup</h2>
        <p>Setup Device Infomation</p><br>
        <form id="Info">
          <label for="Name">Name:</label>
          <input type="text" id="Name" name="Name" required><br><br>
          <label for="Pass">Password:</label>
          <input type="password" id="Password" name="Pass" placeholder="Optional"><br><br>
          <input type="submit">
        </form>
      </div>
  </main>

  <div class="control-panel">
  </div>

  <footer>
    <p>This website is running off a Home Hub Device</p>
    <p>&copy; 2023 Home Hub. All rights reserved.</p>
  </footer>
<script>
function toggleNav() {
  var navList = document.querySelector('.nav-list');
  navList.classList.toggle('active');
  console.log("Nav Toggle");
}

document.getElementById('Info').addEventListener('submit', function (event) {
  event.preventDefault();
  console.log("Trigger 1");
  sendInfo();
});

      function sendInfo() {
        var name = document.getElementById("Name").value;
        var password = document.getElementById("Password").value;
        console.log("Sending Info");
        console.log(name);
        console.log(password);

        var data = {
            Name: name,
            Pass: password
        };
        console.log(JSON.stringify(data));
        
        let url = "/wifi";

        
        
        fetch(url, {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify(data),
        })
            .then(response => {
                if (response.ok) {
                    return response.json();
                } else {
                    throw new Error('Network response was not ok');
                }
            })
            .then(responseData => {
                console.log("Data sent successfully:", responseData);
            })
            .catch(error => console.error('Error sending Data:', error));
        
          }
          document.getElementById('Wifi').addEventListener('submit', function (event) {
  event.preventDefault();

  const ip = document.getElementById('IP').value;
  const subnet = document.getElementById('Subnet').value;

  if ((ip && !subnet) || (!ip && subnet)) {
    alert("Both IP Address and Subnet Mask must be provided if either is entered.");
    return false;
  }

  console.log("Trigger 2");
  sendWifi();

  if (ip) {
    setTimeout(function () {
      window.location.href = 'http://' + ip + '/settings';
    }, 2000);
  }
});


function sendWifi() {
  var SSID = document.getElementById("SSID").value;
  var Password = document.getElementById("Pass").value;
  var IP = document.getElementById("IP").value;
  var Subnet = document.getElementById("Subnet").value;
  console.log("Sending Wifi");

  var data = {
    SSID_Name: SSID,
    Pass: Password,
    IPAddr: IP,
    Subent_Mask: Subnet
  };

  fetch("/wifi", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(data),
  })
    .then(response => {
      if (!response.ok) {
        throw new Error("Network response was not ok");
      }
      return response.json();
    })
    .then(response => {
      console.log("Info sent successfully:", response);
    })
    .catch(error => {
      console.error("Error sending Info:", error);
    });
}

  </script> 
</body>
</html>
)=====";
