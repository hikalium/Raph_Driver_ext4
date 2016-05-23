/*
 *
 * Copyright (c) 2016 Raphine Project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * Author: Levelfour
 *
 */

#include <global.h>
#include <cpu.h>
#include <task.h>
#include <mem/uvirtmem.h>
#include <dev/posixtimer.h>

VirtmemCtrl *virtmem_ctrl;
PthreadCtrl *apic_ctrl;

int main(int argc, char **argv) {
  UVirtmemCtrl _virtmem_ctrl;
  virtmem_ctrl = &_virtmem_ctrl;

  PosixTimer _ptimer;
  timer = &_ptimer;

  PthreadCtrl _thread_ctrl(8);
  _thread_ctrl.Setup();
  cpu_ctrl = &_thread_ctrl;

  TaskCtrl _task_ctrl;
  task_ctrl = &_task_ctrl;
  task_ctrl->Setup();

  // set up application here

  task_ctrl->Run();

  return 0;
}
