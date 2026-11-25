# F450 Simulink 飞行控制器

[English](./README.md)

**已经克隆仓库？** [安全同步远端并获取最新 Homework 模型](#41-已有本地仓库同步最新-homework-模型保留本地修改)。

**Task 2：** [单独下载位置控制仿真](#42-下载-task-2位置控制仿真)。

本仓库包含 F450 四旋翼飞行控制项目的 Simulink 控制器，以及由 Simulink 生成的 ROS 2 软件包。

当前提交的控制器代码由 **MATLAB/Simulink R2023b** 生成，使用 **ERT (`ert.tlc`)** 目标，并面向 **AMD/x86-64 Linux** 平台。生成的 ROS 2 节点名称为 `softdrone_pid`。

> **安全提示：** 第一次编译、ROS 2 联调、PWM 测试或控制器台架测试时，请务必拆下全部桨叶。在安装桨叶前，确认通道映射、电机编号、输出范围和失控保护逻辑全部正确。

---

## 1. 仓库结构

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
        ├── softdrone_pid.slx          # 主 Simulink 模型
        ├── homework13.slx             # Homework 作业模型
        ├── Init_control450.m          # 控制器参数 / 初始化脚本
        ├── +bus_conv_fcns/            # 自动生成的 ROS 2 Bus 转换函数
        └── src/
            ├── custom_msgs/           # ROS 2 自定义消息包
            └── softdrone_pid/         # 自动生成的 ROS 2 控制器包
```

当前生成节点使用以下 ROS 2 接口：

| 方向 | Topic | 类型 |
|---|---|---|
| 订阅 | `/ecat/sn1966143/app1/read` | `custom_msgs/msg/ReadSBUSRC` |
| 订阅 | `/ecat/sn1966143/app2/read` | `sensor_msgs/msg/Imu` |
| 订阅 | `/filtered_angular_acceleration` | `geometry_msgs/msg/Vector3` |
| 发布 | `/ecat/sn1966143/app3/write` | `custom_msgs/msg/WriteOnBoardPWM` |
| 发布 | `/gyro_rotated` | `geometry_msgs/msg/Vector3` |
| 发布 | `/imu_angle` | `geometry_msgs/msg/Vector3` |
| 发布 | `/imu_gyro` | `geometry_msgs/msg/Vector3` |

如果你的 EtherCAT 从站序列号或者 ROS 2 Topic 名称不同，请在 Simulink 模型中修改对应模块，然后重新生成代码。

---

# 2. 推荐环境

当前仓库建议使用：

- **Ubuntu 22.04 LTS x86-64**
- **ROS 2 Humble**
- **MATLAB R2023b**
- **Simulink R2023b**
- **ROS Toolbox**
- **Simulink Coder**
- 当前 ERT 代码生成配置建议安装 **Embedded Coder**

MathWorks 官方支持 MATLAB R2023b 在 Ubuntu 22.04 LTS 上运行。

如果只是查看和修改模型，MATLAB + Simulink 即可。若需要 ROS 2 集成并重新生成当前这种独立 C++ 节点，则建议安装上述 ROS Toolbox、Simulink Coder 和 Embedded Coder。

---

# 3. Linux 下载并安装 MATLAB R2023b

## 3.1 下载 Linux 安装包

进入 MathWorks 官方下载页面：

- https://www.mathworks.com/downloads/

使用与你的个人许可证或学校许可证绑定的 MathWorks 账号登录，选择 **R2023b**，系统选择 **Linux**，然后下载安装压缩包。

R2023b Linux 安装包通常类似：

```text
matlab_R2023b_glnxa64.zip
```

MathWorks 官方 R2023b Linux 安装指南：

- https://www.mathworks.com/help/releases/r2023b/pdf_doc/install/install_guide.pdf

## 3.2 安装 Linux 基础工具

```bash
sudo apt update
sudo apt install -y unzip ca-certificates build-essential git
```

## 3.3 解压 MATLAB 安装包

假设安装包位于 `~/Downloads`：

```bash
cd ~/Downloads
mkdir -p matlab_R2023b_glnxa64
unzip matlab_R2023b_glnxa64.zip -d matlab_R2023b_glnxa64
cd matlab_R2023b_glnxa64
```

## 3.4 启动安装程序

对于本仓库，建议将 MATLAB 安装到：

```text
/usr/local/MATLAB/R2023b
```

这个路径很重要，因为仓库中当前已经生成好的 ROS 2 软件包，在 CMake 中链接了 `/usr/local/MATLAB/R2023b` 下的 MATLAB 动态库。

启动图形化安装器：

```bash
xhost +SI:localuser:root
sudo -H ./install
xhost -SI:localuser:root
```

如果你准备安装到当前普通用户拥有写权限的目录，就不需要 `sudo`，一般可以直接：

```bash
./install
```

安装过程中：

1. 登录 MathWorks 账号。
2. 选择对应许可证。
3. 如果条件允许，将安装目录设为 `/usr/local/MATLAB/R2023b`。
4. 至少安装 MATLAB 和 Simulink。
5. 如果需要重新生成和部署本项目，另外勾选 ROS Toolbox、Simulink Coder 和 Embedded Coder。

## 3.5 将 MATLAB 加入 `PATH`

```bash
echo 'export PATH=/usr/local/MATLAB/R2023b/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
```

验证：

```bash
which matlab
matlab -batch "disp(version)"
```

预期版本应对应：

```text
R2023b
```

也可以直接启动 MATLAB 桌面：

```bash
matlab
```

## 3.6 MATLAB 安装在其他路径怎么办

当前生成的软件包中存在以下 MATLAB 库路径：

```text
/usr/local/MATLAB/R2023b/sys/os/glnxa64/orig/libstdc++.so.6
```

如果你的 MATLAB 安装在其他位置，请修改：

```text
src/simulink/src/softdrone_pid/CMakeLists.txt
```

把里面写死的 `/usr/local/MATLAB/R2023b` 前缀替换成你真实的 MATLAB 根目录。

在 MATLAB 中可以使用下面的命令查看真实根目录：

```matlab
matlabroot
```

---

# 4. 快速打开和修改 Simulink 模型

先克隆仓库：

```bash
git clone https://github.com/ssybh2/F450.git
cd F450/src/simulink
```

在当前目录启动 MATLAB：

```bash
matlab
```

然后在 MATLAB Command Window 中运行初始化脚本：

```matlab
run('Init_control450.m')
```

打开主模型：

```matlab
open_system('softdrone_pid.slx')
```

`Init_control450.m` 中定义了模型使用的主要控制器参数，包括悬停油门、姿态 PID 参数、积分限幅、手动油门限制、最大控制角和一阶时间常数等。

在重新编译前，请检查 ROS 2 Topic、EtherCAT 序列号、PWM 范围、遥控器通道映射、IMU 安装方向和控制器参数是否与你实际飞机一致。

---

## 4.1 已有本地仓库：同步最新 Homework 模型（保留本地修改）

新上传的作业模型是 [`homework13.slx`](./src/simulink/homework13.slx)，与主控制器 `softdrone_pid.slx` 位于同一目录。

**推荐用于已经克隆过仓库的实验室电脑，包括本地 Simulink 模型已经修改过的设备。** 请先保存并关闭 Simulink，在 Ubuntu 终端执行以下命令（要求当前分支为 `main`；若仓库不在 `~/F450`，请替换路径）。

```bash
cd ~/F450 && \
  test "$(git branch --show-current)" = main && \
  git status -sb && \
  git stash push -u -m "F450 local backup before homework update" && \
  git pull --ff-only origin main && \
  git status -sb && \
  ls -lh src/simulink/homework13.slx src/simulink/softdrone_pid.slx
```

上述命令先将已跟踪文件的修改（包括 SLX 模型）以及未跟踪且未被忽略的文件备份到本地 Git stash，再以 fast-forward-only 方式拉取远端 `main`，不产生合并提交。如果本地没有修改，不会创建新的 stash。Git 忽略的文件不包含在备份中，重要的忽略文件需要另行备份。整个过程不会向 GitHub 推送任何修改。

检查备份和同步状态：

```bash
git stash list
git rev-list --left-right --count HEAD...origin/main
```

第二条命令分别显示本地独有、远端独有的提交数，`0 0` 表示提交一致。不要直接执行 `git stash pop`，因为 SLX 是二进制文件，双方同时修改时可能产生冲突。如果需要恢复之前的修改，请从列表中找到对应的备份，再执行 `git stash apply 'stash@{N}'`（将 N 替换为正确编号）；备份仍会保留。如遇冲突，请先检查，不要继续覆盖文件。

**备选方案：完全保留当前本地模型。** 如果希望本地修改继续留在原目录使用，或本地提交与远端分叉、无法快进更新，可以单独创建一份远端 `main` 的干净工作目录：

```bash
cd ~/F450 && \
  git fetch origin && \
  git worktree add --detach "$HOME/F450-homework-$(date +%Y%m%d-%H%M%S)" origin/main
```

该命令会在用户主目录下创建带时间戳的新目录，不覆盖原工作目录，也不改变原分支。若已经执行了前面的 stash，修改仍在 stash 中。不要使用 `git reset --hard` 或 `git clean -fd` 强行解决更新问题。

在更新后的仓库（或新工作目录）的 `src/simulink` 下打开 MATLAB，执行：

```matlab
run('Init_control450.m')
open_system('homework13.slx')
```

仅获取 Homework 模型不需要重新生成或编译 ROS 2 节点，也不会自动部署控制器。

---

## 4.2 下载 Task 2（位置控制仿真）

[Task 2 位置控制模型](./task2/Postion_control.slx)使用 Simulink R2023b 保存。两个初始化脚本和 Simscape Multibody 使用的 CAD 几何文件都在 [task2 目录](./task2/)。

如果本地仓库位于 `~/F450`，要在原仓库中更新 `main`，可在终端执行以下命令。使用其他路径时请替换第一行中的目录。

```bash
cd ~/F450 && git switch main && git pull --ff-only origin main
ls -lh task2/Postion_control.slx task2/Init.m task2/Init_control.m
```

如果本地有正在编辑的模型，也可以将远端的 `task2` 单独导出到新目录。最后一行会打印下载位置。

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

在 MATLAB 中将当前文件夹切换到更新后的 `F450/task2` 或单独导出的 `task2` 目录，然后执行以下命令。

```matlab
% 先将 MATLAB 当前文件夹切换到下载的 task2 目录。
addpath(genpath(fullfile(pwd, 'CAD')));
run('Init_control.m');
open_system('Postion_control.slx');
```

`Init_control.m` 会自动调用 `Init.m`。仅运行此仿真无需重新编译 ROS 2 节点。本次仓库更新未实际运行模型。

---

# 5. 最快部署方式：直接编译仓库中已经生成好的 ROS 2 节点

如果你只想部署仓库当前已经生成好的控制器，这是最快的方法，**不需要先用 Simulink 再生成一次 C++ 代码**。

## 5.1 安装 ROS 2 编译工具

假设系统已经安装 ROS 2 Humble：

```bash
source /opt/ros/humble/setup.bash
sudo apt update
sudo apt install -y python3-colcon-common-extensions python3-rosdep build-essential
```

如果这台电脑之前没有初始化过 `rosdep`：

```bash
sudo rosdep init
rosdep update
```

如果提示 `rosdep init` 已经执行过，直接继续即可。

## 5.2 创建 ROS 2 Workspace

假设仓库克隆在 `~/F450`：

```bash
cd ~/F450
mkdir -p ~/f450_ws/src
cp -r src/simulink/src/custom_msgs ~/f450_ws/src/
cp -r src/simulink/src/softdrone_pid ~/f450_ws/src/
```

如果你的仓库不在 `~/F450`，请把路径替换成实际路径。

## 5.3 安装依赖

```bash
cd ~/f450_ws
source /opt/ros/humble/setup.bash
rosdep install --from-paths src --ignore-src -r -y
```

## 5.4 编译

```bash
cd ~/f450_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install
```

编译成功后：

```bash
source ~/f450_ws/install/setup.bash
```

如果希望每次新开终端自动加载：

```bash
echo 'source /opt/ros/humble/setup.bash' >> ~/.bashrc
echo 'source ~/f450_ws/install/setup.bash' >> ~/.bashrc
```

## 5.5 检查软件包

```bash
ros2 pkg list | grep custom_msgs
ros2 pkg list | grep softdrone_pid
```

检查自定义消息：

```bash
ros2 interface show custom_msgs/msg/ReadSBUSRC
ros2 interface show custom_msgs/msg/WriteOnBoardPWM
```

## 5.6 启动生成好的控制器

**拆下桨叶**后执行：

```bash
source /opt/ros/humble/setup.bash
source ~/f450_ws/install/setup.bash
ros2 run softdrone_pid softdrone_pid
```

另开一个终端：

```bash
source /opt/ros/humble/setup.bash
source ~/f450_ws/install/setup.bash
ros2 node list
ros2 topic list
```

可以继续检查：

```bash
ros2 topic echo /ecat/sn1966143/app1/read
ros2 topic echo /ecat/sn1966143/app2/read
ros2 topic echo /ecat/sn1966143/app3/write
```

控制器运行时要求输入 Topic 正常存在。如果你的 EtherCAT 主站所连接的从站序列号不是 `sn1966143`，建议在 Simulink 中修改 Topic 后重新生成节点，而不是长期依赖当前写死的 Topic 名称。

---

# 6. 从 Simulink 重新生成 ROS 2 节点

当你修改了控制器模型、自定义消息、ROS 2 Topic、采样周期或者代码生成参数之后，请使用这一流程。

## 6.1 加载模型

```bash
cd ~/F450/src/simulink
matlab
```

MATLAB 中执行：

```matlab
run('Init_control450.m')
open_system('softdrone_pid.slx')
```

## 6.2 检查 MathWorks 产品

MATLAB 中执行：

```matlab
ver
```

当前工作流建议至少确认能够看到：

- Simulink
- ROS Toolbox
- Simulink Coder
- Embedded Coder

## 6.3 自定义 ROS 2 消息

本仓库的自定义消息包位于：

```text
src/simulink/src/custom_msgs
```

目前包含：

```text
custom_msgs/msg/ReadSBUSRC
custom_msgs/msg/WriteOnBoardPWM
```

如果把仓库迁移到一台新电脑后，MATLAB 无法识别这些自定义消息，可以在 `F450/src/simulink` 目录下执行：

```matlab
ros2genmsg(fullfile(pwd,'src'))
```

如果 MATLAB 提示需要重启，则重启后重新打开 `softdrone_pid.slx`。

## 6.4 从 Simulink 编译

进入 **Model Settings / Configuration Parameters**，先确认 ROS 2 和代码生成相关设置。

当前仓库提交的生成代码显示，模型配置为：

```text
System target file: ert.tlc
Hardware target: AMD/x86-64 (Linux 64)
MATLAB/Simulink release: R2023b
```

然后使用 Simulink 的 **Build** 命令（通常是 `Ctrl+B`），或者使用当前模型配置好的 ROS 2 Deployment 流程生成代码。

生成成功后，把新生成的 ROS 2 软件包放入 ROS 2 workspace，再重新执行 `colcon build`。

> 不建议为了永久修改控制算法而直接修改生成后的 `.cpp` 文件。应优先修改 `softdrone_pid.slx` 或 `Init_control450.m`，然后重新生成代码，保证 Simulink 模型始终是控制器的源代码来源。

---

# 7. 仓库更新后的快速重新部署

如果需要从原仓库重新部署控制器，请先按照 [4.1 节](#41-已有本地仓库同步最新-homework-模型保留本地修改) 完成安全同步。仅下载 Homework 不需要执行本节。以下命令会替换工作空间中的软件包副本，若其中有本地修改，请先备份。

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

如果需要完全清理后重新编译：

```bash
cd ~/f450_ws
rm -rf build install log
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

---

# 8. 常见问题

### `matlab: command not found`

执行：

```bash
export PATH=/usr/local/MATLAB/R2023b/bin:$PATH
```

然后把这一行加入 `~/.bashrc`。

### CMake 找不到 MATLAB 的 `libstdc++.so.6`

检查：

```bash
ls /usr/local/MATLAB/R2023b/sys/os/glnxa64/orig/libstdc++.so.6
```

如果 MATLAB 安装在其他位置，修改：

```text
src/simulink/src/softdrone_pid/CMakeLists.txt
```

### 找不到 `custom_msgs`

确认两个包都在同一个 workspace 中重新编译，并重新 source：

```bash
cd ~/f450_ws
source /opt/ros/humble/setup.bash
colcon build --symlink-install
source install/setup.bash
```

### ROS 2 Topic 不存在

先检查：

```bash
ros2 node list
ros2 topic list
```

然后确认 EtherCAT/ROS 2 后端确实在发布模型需要的输入 Topic，并检查从站序列号是否与模型一致。

### MATLAB 无法识别自定义 ROS 2 消息

在 `F450/src/simulink` 下执行：

```matlab
ros2genmsg(fullfile(pwd,'src'))
```

如 MATLAB 提示需要重启，则重启后继续。

---

# 9. 第一次台架测试检查清单

安装桨叶前请确认：

- ROS 2 输入 Topic 持续正常更新。
- IMU 坐标轴方向和正负号正确。
- 遥控器通道、范围和 failsafe 正确。
- 电机编号和混控映射正确。
- PWM 最小值、怠速值和最大值正确。
- 每一路电机命令都对应正确的物理电机。
- ARM / DISARM 能按照设计立即允许或停止电机输出。
- 零姿态/中立输入下检查控制器输出是否合理。

只有在软件、通信链路和电机输出全部完成无桨验证后，再进行带桨测试。

---

## License

请遵循本项目源代码和所有第三方依赖对应的许可证。由 MathWorks 产品生成的代码还需要遵循相应的 MathWorks 许可条款。
