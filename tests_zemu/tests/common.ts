import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
]

export const txProxy_proxy_transferKeepAlive =
  '1e0030e9b187efd17adfd88a3beba6917378a27dffdaebd6ccb5d4bd36933ccd572c010004030030e9b187efd17adfd88a3beba6917378a27dffdaebd6ccb5d4bd36933ccd572c07f0a03ff4e56503001b00b07a81791a1dc3aa75e62300000b000000b0a8d493285c2df73290dfb7e61f870f17b41801197a149ca93654499ea3dafe463dccc3c2a833249b90b4c1911b55be117763f3b40377e7b1802b3d7263ea8f'

