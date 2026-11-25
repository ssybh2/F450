# F450 Simulink Flight Controller

[中文说明](./README_CN.md)

**Already cloned?** [Update the repository and download the homework model safely](#41-update-an-existing-clone-and-get-the-latest-homework-model).

**Task 2:** [Download the position-control simulation separately](#42-download-task-2-position-control-simulation).

This repository contains the Simulink controller and generated ROS 2 packages for an F450 quadrotor flight-control project.

The current generated controller was produced with **MATLAB/Simulink R2023b**, uses the **ERT (`ert.tlc`)** target, and targets **AMD/x86-64 Linux**. The generated ROS 2 node is `softdrone_pid`.

> **Safety:** remove all propellers before the first build, ROS 2 integration test, PWM test, or controller bench test. Confirm channel mapping, motor order, output limits, and failsafe behavior before installing propellers.

---

## 1. Repository layout

```text
F450/
├── README.md
├── README_CN.md
├── task2/
│   ├── Init.m
│   ├── Init_control.m
│   ├── Postion_control.slx
│   └── CAD/CAD/Geometry/
└── src/
    └── simulink/
        ├── softdrone_pid.slx          # Main Simulink model
        ├── homework13.slx             # Homework Simulink model
        ├── Init_control450.m          # Controller parameters / initialization
        ├── +bus_conv_fcns/            # Generated ROS 2 bus conversion helpers
        └── src/
            ├── custom_msgs/           # ROS 2 custom message package
            └── softdrone_pid/         # Generated ROS 2 controller package
```

The generated node currently uses the following ROS 2 interfaces:

| Direction | Topic | Type |
|---|---|---|
| Subscribe | `/ecat/sn1966143/app1/read` | `custom_msgs/msg/ReadSBUSRC` |
| Subscribe | `/ecat/sn1966143/app2/read` | `sensor_msgs/msg/Imu` |
| Subscribe | `/filtered_angular_acceleration` | `geometry_msgs/msg/Vector3` |
| Publish | `/ecat/sn1966143/app3/write` | `custom_msgs/msg/WriteOnBoardPWM` |
| Publish | `/gyro_rotated` | `geometry_msgs/msg/Vector3` |
| Publish | `/imu_angle` | `geometry_msgs/msg/Vector3` |
| Publish | `/imu_gyro` | `geometry_msgs/msg/Vector3` |

If your EtherCAT slave serial number or ROS 2 topic names are different, update the corresponding blocks in the Simulink model and regenerate the code.

---

# 2. Recommended environment

The repository is currently aligned with:

- **Ubuntu 22.04 LTS x86-64**
- **ROS 2 Humble**
- **MATLAB R2023b**
- **Simulink R2023b**
- **ROS Toolbox**
- **Simulink Coder**
- **Embedded Coder** for the current ERT code-generation configuration

MathWorks officially supports Ubuntu 22.04 LTS for MATLAB R2023b.

For simply reading/editing the model, MATLAB + Simulink are sufficient. For ROS 2 integration and regenerating the current standalone C++ node, install the code-generation/toolbox products listed above.

---

# 3. Install MATLAB R2023b on Linux

## 3.1 Download the Linux installer

Go to the official MathWorks Downloads page:

- https://www.mathworks.com/downloads/

Sign in with the MathWorks account associated with your personal or university license, select **R2023b**, choose **Linux**, and download the installer archive.

The R2023b Linux archive is normally named similar to:

```text
matlab_R2023b_glnxa64.zip
```

MathWorks R2023b Linux installation guide:

- https://www.mathworks.com/help/releases/r2023b/pdf_doc/install/install_guide.pdf

## 3.2 Install basic Linux tools

```bash
sudo apt update
sudo apt install -y unzip ca-certificates build-essential git
```

## 3.3 Unzip the MATLAB installer

Assuming the archive is in `~/Downloads`:

```bash
cd ~/Downloads
mkdir -p matlab_R2023b_glnxa64
unzip matlab_R2023b_glnxa64.zip -d matlab_R2023b_glnxa64
cd matlab_R2023b_glnxa64
```

## 3.4 Start the installer

The recommended installation directory for this repository is:

```text
/usr/local/MATLAB/R2023b
```

This path is important because the currently generated ROS 2 package links against a MATLAB library under `/usr/local/MATLAB/R2023b`.

Start the graphical installer:

```bash
xhost +SI:localuser:root
sudo -H ./install
xhost -SI:localuser:root
```

If you are installing into a directory owned by your normal user, `sudo` is not required and you can normally run:

```bash
./install
```

During installation:

1. Sign in to your MathWorks account.
2. Select your license.
3. Set the installation folder to `/usr/local/MATLAB/R2023b` if possible.
4. Install at least MATLAB and Simulink.
5. For rebuilding/deploying this project, also select ROS Toolbox, Simulink Coder, and Embedded Coder.

## 3.5 Add MATLAB to `PATH`

```bash
echo 'export PATH=/usr/local/MATLAB/R2023b/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
```

Verify:

```bash
which matlab
matlab -batch "disp(version)"
```

Expected release:

```text
R2023b
```

You can also launch the desktop application with:

```bash
matlab
```

## 3.6 If MATLAB is installed somewhere else

The generated package currently contains this MATLAB-library path:

```text
/usr/local/MATLAB/R2023b/sys/os/glnxa64/orig/libstdc++.so.6
```

If MATLAB is installed elsewhere, edit:

```text
src/simulink/src/softdrone_pid/CMakeLists.txt
```

and replace the hard-coded `/usr/local/MATLAB/R2023b` prefix with your actual MATLAB root.

You can find the MATLAB root from inside MATLAB with:

```matlab
matlabroot
```

---

# 4. Quick start: open and edit the Simulink model

Clone the repository:

```bash
git clone https://github.com/ssybh2/F450.git
cd F450/src/simulink
```

Start MATLAB in this directory:

```bash
matlab
```

Then run the initialization script from the MATLAB Command Window:

```matlab
run('Init_control450.m')
```

Open the model:

```matlab
open_system('softdrone_pid.slx')
```

The initialization script defines the controller constants and PID parameters used by the model, including hover throttle, attitude gains, integral limits, manual throttle limits, maximum control angles, and the first-order time constant.

Before rebuilding, verify that the ROS 2 topic names, EtherCAT serial number, PWM range, RC channel mapping, IMU orientation, and controller parameters match the target aircraft.

---

## 4.1 Update an existing clone and get the latest homework model

The homework model is [`homework13.slx`](./src/simulink/homework13.slx), alongside the main controller `softdrone_pid.slx`.

**Recommended for existing lab computers (including locally edited models):** save your work and close Simulink first. In Ubuntu, run the following in an existing clone on the `main` branch. Adjust `~/F450` if necessary.

```bash
cd ~/F450 && \
  test "$(git branch --show-current)" = main && \
  git status -sb && \
  git stash push -u -m "F450 local backup before homework update" && \
  git pull --ff-only origin main && \
  git status -sb && \
  ls -lh src/simulink/homework13.slx src/simulink/softdrone_pid.slx
```

This backs up tracked changes (including edited SLX models) and untracked, non-ignored files in a local Git stash, then pulls the latest remote `main` without creating a merge commit. If there are no local changes, no new stash is created. Ignored files are not included; back up any important ignored files separately. Nothing is pushed to GitHub.

To inspect saved local work:

```bash
git stash list
git rev-list --left-right --count HEAD...origin/main
```

The two counts are local-only and remote-only commits; `0 0` means the commits match. Do not automatically pop the stash: SLX files are binary and overlapping edits may conflict. If needed, restore the specific saved work later with `git stash apply 'stash@{N}'` (replace N with the correct index from the list); the stash is retained. Stop and inspect any conflicts.

**Alternative: keep the current local models exactly as they are.** If local edits must remain active, or local commits have diverged and fast-forward fails, use a separate clean checkout of remote `main` instead:

```bash
cd ~/F450 && \
  git fetch origin && \
  git worktree add --detach "$HOME/F450-homework-$(date +%Y%m%d-%H%M%S)" origin/main
```

This creates a new timestamped directory under your home directory without overwriting the original working tree or changing its branch. If you already stashed changes in the first workflow, they remain in the stash. Do not use `git reset --hard` or `git clean -fd` to resolve update errors.

Open the homework model from the updated repository (or the new checkout), in its `src/simulink` directory:

```matlab
run('Init_control450.m')
open_system('homework13.slx')
```

Downloading the homework does not regenerate or deploy the ROS 2 controller. No rebuild is needed just to obtain the SLX file.

---

## 4.2 Download Task 2 (position-control simulation)

The [Task 2 position-control model](./task2/Postion_control.slx) was saved with Simulink R2023b. Its initialization scripts and the CAD geometry used by Simscape Multibody are in the [task2 directory](./task2/).

To update an existing clone on `main`, run the following in a terminal. Adjust `~/F450` to your clone location.

```bash
cd ~/F450 && git switch main && git pull --ff-only origin main
ls -lh task2/Postion_control.slx task2/Init.m task2/Init_control.m
```

If you have local model edits, you can also export just the remote `task2` directory to a separate folder. The last line prints its location.

```bash
(
  set -e -o pipefail
  cd ~/F450
  git fetch origin main
  git cat-file -e FETCH_HEAD:task2/Postion_control.slx
  git cat-file -e FETCH_HEAD:task2/CAD/CAD/Geometry
  dest=$(mktemp -d "$HOME/F450-task2-XXXXXX")
  git archive FETCH_HEAD task2 | tar -x -C "$dest"
  ls -lh "$dest/task2"
  echo "Task 2: $dest/task2"
)
```

Set the MATLAB Current Folder to the updated `F450/task2` or the exported `task2` folder, then run the following commands.

```matlab
% Set Current Folder to the downloaded task2 directory first.
addpath(genpath(fullfile(pwd, 'CAD')));
run('Init_control.m');
open_system('Postion_control.slx');
```

`Init_control.m` calls `Init.m` automatically. No ROS 2 rebuild is needed for this simulation. The model has not been run as part of this repository update.

---

# 5. Fastest deployment: build the already generated ROS 2 node

This is the quickest path if you only want to deploy the controller that is already committed to the repository. You do **not** need to regenerate C++ from Simulink first.

## 5.1 Install ROS 2 build tools

Assuming ROS 2 Humble is already installed:

```bash
source /opt/ros/humble/setup.bash
sudo apt update
sudo apt install -y python3-colcon-common-extensions python3-rosdep build-essential
```

Initialize `rosdep` once per machine if necessary:

```bash
sudo rosdep init
rosdep update
```

If `rosdep init` reports that it has already been initialized, continue normally.

## 5.2 Create a ROS 2 workspace

From the cloned repository root:

```bash
cd ~/F450
mkdir -p ~/f450_ws/src
cp -r src/simulink/src/custom_msgs ~/f450_ws/src/
cp -r src/simulink/src/softdrone_pid ~/f450_ws/src/
```

If you cloned the repository to another path, adjust `~/F450` accordingly.

## 5.3 Install dependencies

```bash
cd ~/f450_ws
source /opt/ros/humble/setup.bash
rosdep install --from-paths src --ignore-src -r -y
```

## 5.4 Build

```bash
cd ~/f450_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install
```

Then source the workspace:

```bash
source ~/f450_ws/install/setup.bash
```

Optional: make this automatic for new terminals:

```bash
echo 'source /opt/ros/humble/setup.bash' >> ~/.bashrc
echo 'source ~/f450_ws/install/setup.bash' >> ~/.bashrc
```

## 5.5 Verify the packages

```bash
ros2 pkg list | grep custom_msgs
ros2 pkg list | grep softdrone_pid
```

Inspect the custom interfaces:

```bash
ros2 interface show custom_msgs/msg/ReadSBUSRC
ros2 interface show custom_msgs/msg/WriteOnBoardPWM
```

## 5.6 Run the generated controller

With the propellers removed:

```bash
source /opt/ros/humble/setup.bash
source ~/f450_ws/install/setup.bash
ros2 run softdrone_pid softdrone_pid
```

In another terminal:

```bash
source /opt/ros/humble/setup.bash
source ~/f450_ws/install/setup.bash
ros2 node list
ros2 topic list
```

Useful checks:

```bash
ros2 topic echo /ecat/sn1966143/app1/read
ros2 topic echo /ecat/sn1966143/app2/read
ros2 topic echo /ecat/sn1966143/app3/write
```

The controller expects its input topics to be available. If your EtherCAT master uses another slave serial number, change the Simulink topic configuration and regenerate the node rather than relying on the current hard-coded names.

---

# 6. Regenerate the ROS 2 node from Simulink

Use this workflow after changing the controller model, message definitions, ROS 2 topics, sample time, or code-generation settings.

## 6.1 Load the project

```bash
cd ~/F450/src/simulink
matlab
```

Inside MATLAB:

```matlab
run('Init_control450.m')
open_system('softdrone_pid.slx')
```

## 6.2 Check required MathWorks products

Inside MATLAB:

```matlab
ver
```

For the current workflow, confirm that MATLAB can see at least:

- Simulink
- ROS Toolbox
- Simulink Coder
- Embedded Coder

## 6.3 Custom ROS 2 messages

The custom ROS 2 message package is located at:

```text
src/simulink/src/custom_msgs
```

It defines:

```text
custom_msgs/msg/ReadSBUSRC
custom_msgs/msg/WriteOnBoardPWM
```

If MATLAB cannot resolve these custom messages after moving the repository to a new machine, regenerate the MATLAB custom-message support from the parent directory containing the ROS 2 package:

```matlab
ros2genmsg(fullfile(pwd,'src'))
```

Restart MATLAB if requested, then reopen `softdrone_pid.slx`.

## 6.4 Build from Simulink

Open **Model Settings / Configuration Parameters** and verify the ROS 2 and code-generation configuration before building.

The committed generated code shows that the current model uses:

```text
System target file: ert.tlc
Hardware target: AMD/x86-64 (Linux 64)
MATLAB/Simulink release: R2023b
```

Build the model from the Simulink **Build** command (`Ctrl+B`) or the configured ROS 2 deployment workflow.

After successful generation, use the generated ROS 2 package as the source for your workspace and rebuild with `colcon`.

> Do not manually edit generated controller `.cpp` files for permanent controller changes. Make the change in `softdrone_pid.slx` or `Init_control450.m`, then regenerate the code so the model remains the source of truth.

---

# 7. Update and rebuild after changing the repository

First complete the safe synchronization in [section 4.1](#41-update-an-existing-clone-and-get-the-latest-homework-model) in the original clone if you intend to deploy from it. Only run the following if you actually need to rebuild the ROS 2 controller; it replaces the copied workspace packages, so back up any local workspace changes first.

```bash
cd ~/F450

rm -rf ~/f450_ws/src/custom_msgs ~/f450_ws/src/softdrone_pid
cp -r src/simulink/src/custom_msgs ~/f450_ws/src/
cp -r src/simulink/src/softdrone_pid ~/f450_ws/src/

cd ~/f450_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

For a completely clean rebuild:

```bash
cd ~/f450_ws
rm -rf build install log
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

---

# 8. Common problems

### `matlab: command not found`

```bash
export PATH=/usr/local/MATLAB/R2023b/bin:$PATH
```

Then add the same line to `~/.bashrc`.

### CMake cannot find the MATLAB `libstdc++.so.6`

Confirm:

```bash
ls /usr/local/MATLAB/R2023b/sys/os/glnxa64/orig/libstdc++.so.6
```

If MATLAB is installed elsewhere, update the path in:

```text
src/simulink/src/softdrone_pid/CMakeLists.txt
```

### `custom_msgs` cannot be found

Build both packages in the same workspace and source the result:

```bash
cd ~/f450_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

### ROS 2 topics are missing

First check:

```bash
ros2 node list
ros2 topic list
```

Then verify that your EtherCAT/ROS 2 backend is actually publishing the expected input topics and that the slave serial number matches the model.

### MATLAB cannot recognize custom ROS 2 messages

From `F450/src/simulink`:

```matlab
ros2genmsg(fullfile(pwd,'src'))
```

Then restart MATLAB if required.

---

# 9. First bench-test checklist

Before installing propellers:

- Confirm ROS 2 input topics are updating.
- Confirm IMU axis orientation and sign conventions.
- Confirm RC channels, range, and failsafe behavior.
- Confirm motor order and mixer mapping.
- Confirm PWM minimum/idle/maximum values.
- Confirm each motor command goes to the expected physical motor.
- Confirm arming/disarming immediately removes or enables motor output as designed.
- Check controller output at zero/neutral attitude before attempting flight.

Only proceed to powered propeller tests after the software and signal chain have been verified on the bench.

---

## License

Follow the license terms of the source project and all third-party dependencies. Generated MathWorks code is also subject to the applicable MathWorks license terms.
