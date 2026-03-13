VS中的一个解决方案可以包含多个项目，解决方案更像一个工作台。每一个项目都有许多的设置，其中包括平台、模式等等。如果是一个小型项目，我们的解决方案可能和项目名称相同。
## 修改你的目录
原生的VS的设置很混乱。我们可以在每个项目中进行设置，将配置选为所有配置后，把输出目录改为：`$(SolutionDir)\bin\$(Platform)\$(Configuration)\`。将中间目录改为`$(SolutionDir)\bin\intermediates\$(Platform)\$(Configuration)\`。